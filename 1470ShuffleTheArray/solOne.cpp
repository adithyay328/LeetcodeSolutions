#include <list>
#include <vector>

class Solution {
public:
  std::vector<int> shuffle(std::vector<int>& nums, int n) {
    std::list<int> shuffled;
    for(int i = 0; i < n; i++) {
      shuffled.push_back(nums[i]);
      shuffled.push_back(nums[i + n]);
    }

    for(int i = 0; i < n * 2; i++) {
      nums[i] = shuffled.front();
      shuffled.pop_front();
    }

    return nums;
  }
};
