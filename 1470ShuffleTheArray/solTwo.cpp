#include <vector>

class Solution {
public:
  std::vector<int> shuffle(std::vector<int>& nums, int n) {
    std::vector<int> shuffled;
    shuffled.reserve(n * 2);
    
    for(int i = 0; i < n; i++) {
      shuffled.push_back(nums[i]);
      shuffled.push_back(nums[i + n]);
    }

    return shuffled;
  }
};
