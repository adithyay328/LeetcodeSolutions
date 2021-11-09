#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>


/*

Problem planning:

We're looking for a linear solution. The idea is to go over the entire string once, and figure out the longest
substring that exists in it. To do this, we start at index 0, and then insert all characters we encounter into a hash map.
When we see a duplicate, we have to stop; this means that this substring is over. Now, we need to start a new substring, but with the iterating
variable (i) set to just after the location of the first occurence of the duplicate character. To get there, we need to increment
i until we get to the desired location, deleting all characters that we iterate over in between.

*/
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int longestLength = 0;
        
        // Key = char, value = index of occurence
        std::unordered_map<char, int> charSet;

        for(int i = 0; i < s.length(); i++) {
            longestLength = std::max(1, longestLength);

            if( charSet.count(i) == 0 ) {
                charSet.insert ( {s[i], i} );
            }
            else {
                if(charSet.size() > longestLength) {
                    longestLength = charSet.size();
                }

                int indexOfDuplicate = charSet.at(s[i]);
                int desiredValueOfI = indexOfDuplicate + 1;

                while (i <= desiredValueOfI) {
                    char charToRemove = s[i];
                    charSet.erase(charToRemove);
                    i++;
                }
            }
        };

        return longestLength;
    }
};

int main() {
    Solution mySol;
    int ret = mySol.lengthOfLongestSubstring( "au" );
    std::cout << ret << std::endl;

    return ret;
}