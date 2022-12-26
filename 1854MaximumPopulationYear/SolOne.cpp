#include<vector>
#include<unordered_map>
#include <bits/stdc++.h>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
      int maxPop = -1;
      int maxYear = INT_MAX;
      unordered_map<int, int> liveMap;

      for(auto it = logs.begin(); it < logs.end(); it++) {
        // Iterate over the years they were alive(end excluded),
        // incrementing the liveMap's value by 1 or setting it to 1
        // if that key doesn't exist
        for(int year = (*it)[0]; year < (*it)[1]; year++) {
          if(liveMap.count(year) == 0) {
            // If that key doesn't exist, set it to 1
            liveMap[year] = 1;
          }
          else {
            // Increment key otherwise
            liveMap[year] += 1;
          }

          // Update our solution if this is better
          if(liveMap[year] > maxPop || liveMap[year] == maxPop && year < maxYear) {
            maxPop = liveMap[year];
            maxYear = year;
          }
        }
      }

      return maxYear;
    }
};