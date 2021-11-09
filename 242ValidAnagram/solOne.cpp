#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
      std::unordered_map<char, int> charFreqS;
      std::unordered_map<char, int> charFreqT;

      if(s.length() != t.length()) {
	return false;
      }
      
      for(int i = 0; i < s.length(); i++) {
	if( charFreqS.count( s[i] ) == 0 ) {
	  charFreqS.insert ( {s[i], 1} ) ;
	}
	else {
	  int currFreq = charFreqS.at( s[i] );
	  currFreq++;

	  charFreqS.erase( s[i] );
	  charFreqS.insert ( { s[i], currFreq } );
	}
      }

      for(int i = 0; i < t.length(); i++) {
	if( charFreqT.count( t[i] ) == 0 ) {
          charFreqT.insert ( {t[i], 1} ) ;
        }
        else {
          int currFreq = charFreqT.at( t[i] );
          currFreq++;

          charFreqT.erase( t[i] );
          charFreqT.insert ( { t[i], currFreq } );
        }
      }

      return charFreqS == charFreqT;
    }
};
