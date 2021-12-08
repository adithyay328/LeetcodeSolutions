class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      //Instead of starting our search from index 0, start from where the last
      //search ended.
      int startIndex = 0;
      for(int i = 0; i < nums2.size(); i++) {
	if(m > 0) {
	  //if this number is bigger than everything in num1, just toss it on the end
	  if(nums2[i] >= nums1[m-1]) {
	    nums1[m] = nums2[i];
	    m++;
	  }
	  
	  else {
	    
	    for(int j = startIndex; j < nums1.size(); j++) {
	      if(nums2[i] <= nums1[j]) {
		//Shifting all elements after the desired index to the right by 1
		for(int k = nums1.size() - 1; k > j; k--) {
		  nums1[k] = nums1[k - 1];
		}
		
		nums1[j] = nums2[i];
		m++;
		
		startIndex = j;
		break;
	      }
	    }
	  }
	}
	
	else {
	  for(int i = 0; i < nums2.size(); i++) {
	    nums1[i] = nums2[i];
	  }
	}
      }
    }
};
