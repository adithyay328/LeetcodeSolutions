#include <cmath>

class Solution {
public:
    int mySqrt(int num) {
      if(num <= 1) {
	return 1 * num;
      }
      
      long lowerBound = 1;
      long upperBound = num;

      long square = lowerBound * lowerBound;
      
      while( !(lowerBound * lowerBound <= num && (lowerBound + 1) * (lowerBound + 1) > num) ) {
	long mid = (int)std::ceil( 1.0 * (lowerBound + upperBound) / 2 );
	
	square = mid * mid;
	
	if(square <= num) {
	  lowerBound = mid;
	}

	else if(square > num) {
	  upperBound = mid;
	}
      }

      return lowerBound;
    }
};
