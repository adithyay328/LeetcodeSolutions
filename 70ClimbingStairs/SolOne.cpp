class Solution {
public:
  int climbStairs(int n) {
    if(n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    } else {
      int lesser = 1;
      int upper = 2;
      int currN = 2;
      for(int currN = 2; currN < n; currN++) {
        int next = upper + lesser;
        lesser = upper;
        upper = next;
      }

      return upper;
    }
  }
};