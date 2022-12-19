#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
      // Skip if it's impossible due to sizes
      if(needle.size() > haystack.size()) {
        return -1;
      }

      // Iterate over, only looking at equal size strings
      for(int i = 0; i < haystack.size() - needle.size() + 1; i++) {
        bool succesfulMatch = true;
        // Iterate over window, failing as fast as we can
        for(int j = 0; j < needle.size(); j++) {
          if(haystack[j + i] != needle[j]) {
            succesfulMatch = false;
            break;
          }
        }

        if(succesfulMatch) {
          return i;
        }
      }

      return -1;
    }
};