#include <string>
#include <stack>

using std::string;

class Solution {
public:
  // Reverse substring of string between indices(swap inclusive on both ends)
  void reverseBetweenIndices(string& target, int start, int end) {
    char swap;
    while(start < end) {
      swap = target[start];
      target[start] = target[end];
      target[end] = swap;

      start++;
      end--;
    }
  }

  string reverseParentheses(string s) {
    std::stack<int> prevPars;
    // Iterate over string, and store the indices of the parantheses
    // inside the stack
    for(int i = 0; i < s.size(); i++) {
      char curr = s[i];
      if(curr == '(') {
        prevPars.push(i);
      // Otherwise reverse chars
      } else if(curr == ')') {
        int lastAddress = prevPars.top();
        prevPars.pop();

        // Swap all chars in between
        reverseBetweenIndices(s, lastAddress + 1, i - 1);
      }
    }

    // Now iterate again, this time adding all non parantheses chars to
    // new string 
    std::string result;
    for(int i = 0; i < s.size(); i++) {
      char curr = s[i];
      if(!(curr == '(' || curr == ')')) {
        result += curr;
      }
    }

    return result;
  }
};