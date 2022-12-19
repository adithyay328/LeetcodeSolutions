#include <string>

using std::string;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      for(int subStringLen = 1; subStringLen <= s.size() / 2; subStringLen++) {
        // Skip if the sub string length isn't a multiple of sub string len
        if(s.size() % subStringLen != 0) {
          continue;
        }

        // If not, check if this sub string works; outer loop
        // iterates over the digits in the first occurence of the
        // substring
        for(int i = 0; i < subStringLen; i++) {
          bool isSubStringPlausible = true;
          // Now, check if i + n * sub string length is equal to the
          // character in the first substring, if i + n * sub string length is
          // less than the length of the whole string
          for(int indToCheck = i + subStringLen; indToCheck < s.size(); indToCheck += subStringLen) {
            if(s[i] != s[indToCheck]) {
              isSubStringPlausible = false;
              break;
            }
          }

          if(!isSubStringPlausible) {
            break;
          }

          // If we made it to the end, return true
          if(i == subStringLen - 1) {
            return true;
          }
        }
      }

      return false;
    }
};