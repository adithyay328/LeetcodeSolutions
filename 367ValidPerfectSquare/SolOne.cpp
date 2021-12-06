#include <cmath>

class Solution {
public:
    bool isPerfectSquare(int num) {
      if(num == 1) {
	return true;
      }
      
      long lowerBound = 1;
      long upperBound = num;

      long square = lowerBound * lowerBound;
      
      while(square != num && lowerBound != upperBound) {
	long mid = (int)std::ceil( 1.0 * (lowerBound + upperBound) / 2 );
	if(mid * mid == square) {
	  break;
	}
	
	square = mid * mid;
	
	if(square < num) {
	  lowerBound = mid;
	}

	else if(square > num) {
	  upperBound = mid;
	}

	else {
	  return true;
	}
      }

      return false;
    }
};
