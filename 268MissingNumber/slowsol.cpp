#include <unordered_set>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
      std::unordered_set<int> valSet;
      for(int i = 0; i < nums.size(); i++) {
	if(valSet.count(nums[i]) == 0) {
	  valSet.insert( {nums[i] } );
	}
      }

      for(int i = 0; i <= nums.size(); i++) {
	if(valSet.count(i) == 0) {
	  return i;
	}
      }

      return -1;
    }
};
