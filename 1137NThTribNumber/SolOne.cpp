class Solution {
public:
    int tribonacci(int n) {
      switch(n) {
        case 0:
          return 0;
        case 1:
          return 1;
        case 2:
          return 1;
        default:
          int small = 0;
          int mid = 1;
          int big = 1;

          for(int i = 2; i < n; i++) {
            int next = small + mid + big;

            small = mid;
            mid = big;
            big = next;
          }

          return big;
      }
    }
};