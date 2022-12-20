#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::abs;
using std::max;

// Maximize this objective function over our array
int objective(vector<int>& heightArr, int iOne, int iTwo) {
  return ( abs(iOne - iTwo) ) * min(heightArr[iOne], heightArr[iTwo]);
}

class Solution {
public:
    int maxArea(vector<int>& height) {
      int i = 0;
      int sol = 0;
      int j = height.size() - 1;
      
      while(i < j) {
        sol = max(sol, objective(height, i, j));
        
        // If the second index isn't a limiting factor for objective
        if(height[i] <= height[j]) {
          i++;
        } else {
          // Now it is a limiting factor, reduce to hopefully find a higher value that
          // isn't a limiting factor
          j--;
        }
      }

      return sol;
    }
};