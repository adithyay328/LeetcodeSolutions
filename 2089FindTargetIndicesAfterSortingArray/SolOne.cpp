class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
      int countLessThan = 0;
      int countEqualTo = 0;

      for(int i = 0; i < nums.size(); i++) {
	if(nums[i] < target) {
	  countLessThan++;
	}
	else if(nums[i] == target) {
	  countEqualTo++;
	}
      }

      std::vector<int> results;

      if(countEqualTo > 0) {
	for(int i = 0; i < countEqualTo; i++) {
	  results.push_back(countLessThan + i);
	}
      }
      
      return results;
    }
};
