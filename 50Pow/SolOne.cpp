class Solution {
public:
    double myPow(double x, int n) {
        // Trick; use binary arithmetic to know when to multiply, and when not to
        // If n is negative, just invert x
        long nReal = n;
        if(nReal < 0) {
            nReal = nReal * -1;
            x = 1/x;
        }

        // Now, multiply
        double result = 1;
        double multiplier = x;
        while(nReal > 0) {
          if(nReal % 2 == 1) {
              result *= multiplier;
          }
          multiplier = multiplier * multiplier;
          nReal = nReal >> 1;
        }

        return result;
    }
};
