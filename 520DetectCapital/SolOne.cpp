#include <cctype>

class Solution {
public:
  bool detectCapitalUse(string word) {
    int upCount = 0;
    for(int i = 0; i < word.size(); i++) {
      if(word[i] == std::toupper(word[i])) {
	upCount++;
      }
    }

    if(upCount == 0) {
      return true;
    }
    else if(upCount == word.size()) {
      return true;
    }
    else if(upCount == 1 && word[0] == std::toupper(word[0])) {
      return true;
    }
    else {
      return false;
    }
  }
};
