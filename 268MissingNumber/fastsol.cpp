class Solution {
public:
    int missingNumber(vector<int>& nums) {
      //This is just a summation property, maybe a proof of this would be fun
      int sum = ( nums.size() * ( nums.size() + 1) ) / 2;
      int actualSum = 0;

      for(int i = 0; i < nums.size(); i++) {
	actualSum += nums[i];
      }

      return sum - actualSum;
    }
};
