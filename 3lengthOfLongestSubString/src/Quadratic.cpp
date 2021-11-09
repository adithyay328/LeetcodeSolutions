#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int longestLength = 0;
        for(int i = 0; i < s.length(); i++) {
            // If this string has atleast one character, set longestlength to ATLEAST 1
            longestLength = std::max(1, longestLength);

            std::unordered_set<char> currentCharsInString;
            for(int j = i; j < s.length(); j++) {
                if(currentCharsInString.count(s.at(j)) == 0) {
                    currentCharsInString.insert( { s.at(j) } );
                }
                else {
                    break;
                }
            }

            if( currentCharsInString.size() > longestLength) {
                longestLength = currentCharsInString.size();
            }
        }

        return longestLength;
    }
};

int main() {
    Solution mySol;
    int ret = mySol.lengthOfLongestSubstring( "au" );
    std::cout << ret << std::endl;

    return ret;
}