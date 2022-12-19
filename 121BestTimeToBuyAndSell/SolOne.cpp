// This is a really slow first attempt at this.

#include <vector>
#include <list>
#include <map>
#include <algorithm>

using std::vector;
using std::list;
using std::map;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // Current best profit
      int bestProfit = 0;

      // List storing values as we see them
      list<int> vals;

      // Map storing key(value) and value(count). Allows for fast
      // minimum look ups
      map<int, int> valueCounts;

      // Iterate forwards over the values of the input vector, and init
      // our structurs
      for(auto it = prices.begin(); it != prices.end(); it++) {
        // Add to vals
        vals.push_back(*it);

        // Increase count in map if it's in there, or init if not in there
        if( valueCounts.find(*it) != valueCounts.end() ) {
          // If found, increment count
          valueCounts[*it] += 1;
        } else {
          // Otherwise init to 1
          valueCounts[*it] = 1;
        }
      }

      // Now, iterate backwards over the list we constructed until we hit the beginning;
      // at each point, compute maximum profit given the current sell point
      for(auto it = vals.rbegin(); it != vals.rend(); it++) {
        // Get the current price
        int currPrice = *it;

        // Compute maximum profit by getting iterator to minimum of map,
        // and subtracting that
        auto mapMinValIterator = valueCounts.begin();
        int mapMinVal = mapMinValIterator -> first;
        int maxProfit = currPrice - mapMinVal;

        // Update bestProfit if it's no longer the biggest
        bestProfit = max(bestProfit, maxProfit);

        // Now that best profit is computed, remove the current list value from the map,
        // removing the key from the map entirely if the count is <= 0.
        valueCounts[currPrice] -= 1;
        if (valueCounts[currPrice] <= 0) {
          valueCounts.erase(currPrice);
        }
      }

      return bestProfit;
    }
};