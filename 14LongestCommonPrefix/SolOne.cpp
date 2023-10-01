#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string ans;

      char curr;

      // Incrementally add the first element of strs,
      // until it's no longer the first element
      for(int i = 0; i < strs[0].length(); i++) {
        bool add = true;
        for(int j = 1; j < strs.size(); j++) {
          if(i >= strs[j].size() || strs[0][i] != strs[j][i]) {
            add = false;
            break;
          }
        }

        if(add) {
          ans += strs[0][i];
        } else {
          break;
        }
      }

      return ans;
    }
};
