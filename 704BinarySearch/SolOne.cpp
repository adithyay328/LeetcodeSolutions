#include <iostream>

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int startIndex = 0;
      int bigIndex = nums.size() - 1;
      
      while(nums[startIndex] < target && nums[bigIndex] > target) {
	std::cout << startIndex << std::endl << bigIndex << std::endl;
	
	int midIndex = (int)( (bigIndex + startIndex) / 2 );
	if(nums[midIndex] == target) { return midIndex; }

	else if(nums[midIndex] > target) {
	  startIndex = midIndex - 1;
	}

	else {
	  bigIndex = midIndex + 1;

	  //If the range between start and big index is odd, then
	  //the trunaction within mixIndex would skip one int/
	  //To fix this, add an extra to bigIndex
	  if( ( bigIndex - startIndex ) % 2 == 1 ) {
	    bigIndex++;
	  }
	}

	std::cout << startIndex	<< std::endl <<	bigIndex << std::endl;
      }
      
      if(nums[startIndex] == target) { return startIndex;  }
      else if(nums[bigIndex] == target) { return bigIndex;  }
      else {
	return -1;
      }
    }
};
