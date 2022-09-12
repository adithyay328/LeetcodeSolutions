#include <vector>
#include <unordered_map>
#include <string>

using std::vector;

// Sums the values in a string
int sumString(std::string& solString) {
  int sum = 0;
  for(int i = 0; i < solString.size(); i++) {
    int indexVal = solString[i]  - '0';
    sum += indexVal;
  }

  return sum;
}

// Increment the string solution, respecting the
// maximum value of each digit and only returning
// strings with a unique set of digits. Returns an
// empty string if no solution is found
std::string nextSolution(std::string prevSol, int maxDigitVal, int correctSum) {
  bool isSumCorrect = false;

  while(!isSumCorrect) {
    // Start by incrementing by 1
    for(int i = prevSol.size() - 1; i >= 0; i--) {
      int currIndexInt = prevSol[i] - '0';
      currIndexInt++;

      if(currIndexInt > maxDigitVal) {
        // If this is the most significant digit, there are no more
        // solutions
        if (i == 0) {
          return "";
        } else {
          // Set current digit to 0
          prevSol[i] = '0';
          
          // Increment the more significant digit
          int moreSigDigit = prevSol[i - 1] - '0';
          moreSigDigit++;
          
          // If this digit is still valid, set the digit in the string.
          // Otherwise, let the loop continue and it will continue
          // incrementing
          if (moreSigDigit <= maxDigitVal) {
            prevSol[i - 1] = '0' + moreSigDigit;
            break;
          }
        }
      }
    }
  
    // Now, check if the digits are unique. If yes, return this
    // solution. Otherwise, keep running
    int currSum = sumString(prevSol);
    isSumCorrect = (correctSum == currSum);
  }

  return prevSol;
}

// Adds a solution string to the solution vector
void addSolutionString(std::string& solString, vector<vector<int>>& solutionSet, vector<int>& sourceVec) {
  std::vector<int> currSol;
  currSol.reserve(solString.size());

  for(int i = 0; i < solString.size(); i++) {
    int currSourceIndex = solString[i] = '0';
    int currValue = sourceVec[currSourceIndex];
    currSol.push_back(currValue);
  }

  solutionSet.push_back(currSol);
}

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;

    // n! possible permutations, so reserve enough space
    int possiblePermutations = 1;
    for(int i = 2; i <= nums.size(); i++) {
      possiblePermutations = possiblePermutations * i;
    }

    result.reserve(possiblePermutations);

    // To solve this, treat the problem as trying to find the next largest
    // arrangement of source vector indices. Then, replace all source indices
    // with the value at that source index, and then you have the solution.

    // To determine if we have any duplicates in the current possible solution,
    // sum all of the values in the current solution, and see if it matches the
    // correct sum for a solution with all unique values

    // Initialize the current solution
    std::string currentSol = "";
    for(int i = 0; i < nums.size(); i++) {
      currentSol += std::to_string(i);
    }

    int correctSum = sumString(currentSol);

    // Add initial solution to set
    addSolutionString(currentSol, result, nums);

    // Generate all permutations
    for(int i = 0; i < possiblePermutations - 1; i++) {
      // Get a new solution
      currentSol = nextSolution(currentSol, nums.size() - 1, correctSum);

      // Add solution to the result set
      addSolutionString(currentSol, result, nums);
    }

    return result;
  }
};

int main() {
  Solution mySol;
  vector<int> myVec{1, 2, 3, 4};
  mySol.permute(myVec);
}