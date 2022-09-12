#include <vector>
#include <map>

using std::vector;

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    std::map<int, int> playerToLoss;

    // First run through the matches and count up wins and losses for the players
    for(auto it = matches.begin(); it != matches.end(); it++) {
      vector<int> currMatch = *it;
      int winner = currMatch[0];
      int loser = currMatch[1];
      
      // Create our winner if they don't exist
      if(playerToLoss.count(winner) == 0) {
        playerToLoss[winner] = 0;
      }
      
      // Create our loser if they don't exist, and update their
      // losses otherwise
      if(playerToLoss.count(loser) == 0) {
        playerToLoss[loser] = 1;
      } else {
        playerToLoss[loser] += 1;
      }
    }

    // Now, iterate through our btree, and add them to our result list
    vector<vector<int>> solutions;
    solutions.push_back( vector<int>() );
    solutions.push_back( vector<int>() );

    for(auto it = playerToLoss.begin(); it != playerToLoss.end(); it++) {
      int player = it -> first;
      int losses = it -> second;

      if(losses == 0) {
        solutions[0].push_back(player);
      } else if(losses == 1) {
        solutions[1].push_back(player);
      }
    }

    return solutions;
  }
};