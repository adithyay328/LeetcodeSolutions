#include <unordered_set>

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> result;
    
    std::unordered_set<int> inOne;
    for(int i = 0; i < nums1.size(); i++) {
      if(inOne.count(nums1[i]) == 0) {
	inOne.insert( {nums1[i]}  );
      }
    }

    result.reserve(inOne.size());
    for(int i = 0; i < nums2.size(); i++) {
      if(inOne.count(nums2[i]) != 0) {
	result.push_back(nums2[i]);
	inOne.erase(nums2[i]);
      }
    }

    return result;
  }
};
