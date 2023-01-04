#include <vector>
#include <cstdlib>
#include <limits.h>

using std::vector;
using std::abs;

class Solution {
  public:
    int findClosestNumber(vector<int>& nums) {
      int minDist = abs(nums[0]);
      int maxVal = nums[0];

      for(int i = 1; i < nums.size(); i++) {
        if(abs(nums[i]) < minDist || abs(nums[i]) == minDist && nums[i] > maxVal) {
          minDist = abs(nums[i]);
          maxVal = nums[i];
        }
      }

      return maxVal;
    }
};