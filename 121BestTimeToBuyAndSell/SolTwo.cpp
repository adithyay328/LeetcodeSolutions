#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::min;
using std::max;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // Return 0 if length is 1
      if(prices.size() == 1) {
        return 0;
      }
      
      // Initialize min price and max profit
      int minPrice = prices[0];
      int maxProfit = 0;

      // Update min price and max profit on the rest of the list
      for(int i = 1; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
      }

      // Return the greater of 0 and the max profit
      return max(0, maxProfit);
    }
};