#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
private:
  // Computing time to move a truck to a certain index
  int timeToMoveTruck(int currIndex, int targetIndex, vector<int>& travel) {
    int time = 0;
    
    // Sum up travel cost
    for(int i = currIndex; i < targetIndex; i++) {
      time += travel[i];
    }

    return time;
  }

public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int mTruck = 0, pTruck = 0, gTruck = 0;
    int time = 0;

    for(int houseIndex = 0; houseIndex < garbage.size(); houseIndex++) {
      string currString = garbage[houseIndex];
      for(int stringIndex = 0; stringIndex < currString.size(); stringIndex++) {
        // One if case for each possible garbage type
        switch (currString[stringIndex]) {
          case 'M':
            // Factor in time to move to current position if not here right now
            if(mTruck < houseIndex) {
              // Update time
              int timeToMove = timeToMoveTruck(mTruck, houseIndex, travel);
              time += timeToMove;

              // Update position
              mTruck = houseIndex;
            }
            break;
          case 'P':
            // Factor in time to move to current position if not here right now
            if(pTruck < houseIndex) {
              // Update time
              int timeToMove = timeToMoveTruck(pTruck, houseIndex, travel);
              time += timeToMove;

              // Update position
              pTruck = houseIndex;
            }
            break;
          case 'G':
            // Factor in time to move to current position if not here right now
            if(gTruck < houseIndex) {
              // Update time
              int timeToMove = timeToMoveTruck(gTruck, houseIndex, travel);
              time += timeToMove;

              // Update position
              gTruck = houseIndex;
            }
            break;
        }
        
        // Add the time to pick up this piece of garbage
        time++;
      }
    }

    return time;
  }
};