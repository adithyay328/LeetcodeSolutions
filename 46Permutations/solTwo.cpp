#include <vector>
#include <unordered_set>
#include <string>
#include <stack>

using std::vector;

// Recursively generates more solutions
void permuteRecursive(vector<int>& nums, std::string currentSol, vector<vector<int>>& solList) {
  // Check all index values, and see which ones haven't been used yet
  for(int i = 0; i < nums.size(); i++) {
    // If not in string, either call to another level of recursion or realize
    // this is base case and add to solution
    if(currentSol.find(std::to_string(i)) == std::string::npos) {
      // Base Case
      if(currentSol.size() == nums.size() - 1) {
        std::string newSol = currentSol + std::to_string(i);

        // Iterate over each character in string, cast to int, 
        // find the actual value in the nums array, and then construct
        // solution array
        std::vector<int> newSolVector;

        for(int j = 0; j < newSol.size(); j++) {
          int currSourceIndex = newSol[j] - '0';
          newSolVector.push_back( nums[currSourceIndex] );
        }

        // Add to the sol list
        solList.push_back(newSolVector);
      }
      // Not the base case
      else {
        permuteRecursive(nums, currentSol + std::to_string(i), solList);
      }
    }
  }
};

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> allSols;

    // n! possible permutations, so reserve enough space
    int possiblePermutations = 1;
    for(int i = 2; i <= nums.size(); i++) {
      possiblePermutations = possiblePermutations * i;
    }

    allSols.reserve(possiblePermutations);

    // We're solving this recursively - just keep calling
    // back into the function, and return a vector 
    permuteRecursive(nums, "", allSols);

    return allSols;
  }
};