#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++) {
            if(hashmap.count(nums[i]) != 0) {
                std::vector<int> result;
                result.push_back(i);
                result.push_back(hashmap.at(nums[i]));

                return result;
            }
            int complement = target - nums[i];
            hashmap.insert({complement, i});
        }
    }
};