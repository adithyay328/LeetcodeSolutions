#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <array>
#include <iostream>

using namespace std;

#define unset unordered_set
#define unmset unordered_multiset
#define unmap unordered_map
#define unmmap unordered_multimap
#define vec vector
#define arr array

using indexPair = pair<int, int>;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    // Going to verify against these 3 nested arrays
    arr<arr<bool, 9>, 9> rows, cols, squares;

    // Set all to false
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        rows[i][j] = false;
        cols[i][j] = false;
        squares[i][j] = false;
      }
    }

    for(int row = 0; row < board.size(); row++) {
      for(int col = 0; col < board[0].size(); col++) {
        const int squareNum = (row / 3) * 3 + col / 3;

        const char currChar = board[row][col]; 

        if( board[row][col] == '.' ) {
          continue;
        }

        // If this is an actual value, start by getting the
        // integer corresponding to the current board position.
        const int currValZeroIndexed = currChar - 48 - 1;

        // Attempt to set all corresponding vals to true, and error if
        // valse

        if(rows[row][currValZeroIndexed] || cols[col][currValZeroIndexed] || squares[squareNum][currValZeroIndexed]) {
          return false;
        }

        // Set all to true
        rows[row][currValZeroIndexed] = true;
        cols[col][currValZeroIndexed] = true;
        squares[squareNum][currValZeroIndexed] = true;
      }
    }

    return true;
  }
};
