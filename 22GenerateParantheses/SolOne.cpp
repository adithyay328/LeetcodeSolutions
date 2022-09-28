#include <string>
#include <list>
#include <vector>

using std::vector;
using std::string;

// Going to solve this with backtracing. Standard
class Solution {
// The recursive function that actually implements the generation.

// NumRemaining is how many parantheses we can open still
// NumOpen is how many parantheses are already open
// close is whether this invocation should close a paranth. or open one
std::list<string> genParRecursive(int numRemaining, int numOpen, bool close, string currString) {
  std::list<string> newSols;
  
  // The bulk of this will happen while we have the option to open more parantheses
  if(numRemaining > 0) {
    string newString;
    int newRemaining;
    int newOpen;
    
    if(!close) {
      newString = currString + "(";
      newRemaining = numRemaining - 1;
      newOpen = numOpen + 1;
    } else {
      newString = currString + ")";
      newRemaining = numRemaining;
      newOpen = numOpen - 1;
    }
    
    // If there are any parantheses left to close
    if(newOpen > 0) {
      std::list<string> closeSols = genParRecursive(newRemaining, newOpen, true, newString);
      newSols.splice(newSols.end(), closeSols);
    }

    // If we can still open more
    if(newRemaining > 0) {
      std::list<string> openSols = genParRecursive(newRemaining, newOpen, false, newString);
      newSols.splice(newSols.end(), openSols);
    }
  }
  // If the above condition failed, the only thing we can really do at this point is close all the parantheses we've
  // already opened
  else {
    if(numOpen > 0) {
      string newString = currString + ")";
      int newRemaining = numRemaining;
      int newOpen = numOpen - 1;

      std::list<string> closeSols = genParRecursive(newRemaining, newOpen, true, newString);
      newSols.splice(newSols.end(), closeSols);
    } else {
      newSols.push_back(currString);
    }
  }

  return newSols;
}

public:
  vector<string> generateParenthesis(int n) {
    std::list<string> sols = genParRecursive(n, 0, false, "");

    std::vector<string> vecSols;
    vecSols.reserve(sols.size());

    for(auto it = sols.begin(); it != sols.end(); it++) {
      vecSols.push_back(*it);
    }

    return vecSols;
  }
};