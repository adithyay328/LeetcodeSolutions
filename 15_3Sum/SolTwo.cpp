#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <array>
#include <iostream>

using namespace std;

#define unset unordered_set
#define unmset unordered_multiset
#define unmap unordered_map
#define unmmap unordered_multimap
#define vec vector
#define arr array

using indexPair = pair<int, int>;

bool pContains(const indexPair& pair, const int& index) {
  return std::get<0>(pair) == index || std::get<1>(pair) == index;
};

class Solution {
public:
  vec<vec<int>> threeSum(vec<int>& nums) {
    // Start by just sorting nums
    sort(nums.begin(), nums.end());

    vec<vec<int>> actualSols;

    // This is a unordered set of all solutions, stored
    // as strings
    unset<string> sols;

    // Now, an unordered multimap from value to index. The idea
    // is that we want to make sure that we aren't usng indices
    // that are duplicate
    unmmap<int, int> valToIdx;

    // Time to populate the above map
    for(int i = 2; i < nums.size(); i++) {
      valToIdx.emplace( make_pair(nums[i], i) );
    }

    // Now, a double for loop over the first 2 indices.

    // These 2 variables keep track of duplicate is and js. Allows us
    // to skip duplicates easily.
    int lastValI = nums[0] - 1;
    int lastValJ = lastValI - 1;

    for(int i = 0; i < nums.size(); i++) {
      const int valI = nums[i];

      if(valI == lastValI) {
        continue;
      } else {
        lastValI = valI;
      }
      
      for(int j = i + 1; j < nums.size(); j++) {
        // Our goal now is to check if the last value exists 
        const int valJ = nums[j];

        // Skip if duplicate
        if( valJ == lastValJ ) {
          continue;
        } else {
          lastValJ = valJ;
        }

        const int neededVal = -1 * (valI + valJ);

        // Check the map, and check if any values aren't equal to
        // i or j
        auto range = valToIdx.equal_range(neededVal);

        for(auto it = range.first; it != range.second; it++) {
          if(it -> second != i && it -> second != j ) {
            vec<int> posSol {valI, valJ, it -> first};
            sort(posSol.begin(), posSol.end());

            const string rep = to_string(posSol[0]) + "_" + to_string(posSol[1]) + "_" + to_string(posSol[2]);
            if(sols.count(rep) == 0) {
              actualSols.push_back(posSol);
              sols.insert(rep);
              break;
            }
          }
        }
      }
    }

    return actualSols;
  }
};