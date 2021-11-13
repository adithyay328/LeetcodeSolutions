class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int bestVectorSum = nums[0];

      int startIndexOfCurrentVector = 0;
      int endIndexOfCurrentVector = 1;
      int currentVectorSum = nums[0];

      for(int i = 1; i < nums.size(); i++) {
	//Calculates the sum with the next element, and without the first element
	int lastSum = currentVectorSum - nums[startIndexOfCurrentVector];
	
	while(lastSum > currentVectorSum) {
	  currentVectorSum = lastSum;
	  startIndexOfCurrentVector++;

	  lastSum = currentVectorSum - nums[startIndexOfCurrentVector];
	}

	int nextSum = currentVectorSum + nums[i];
	
	if(! ( nextSum > currentVectorSum ) ) {
	  if( currentVectorSum > bestVectorSum ) {
	    bestVectorSum = currentVectorSum;
	  }
	}
	
	currentVectorSum = nextSum;
	endIndexOfCurrentVector++;
      }

      return std::max(bestVectorSum, currentVectorSum);
    }
};
