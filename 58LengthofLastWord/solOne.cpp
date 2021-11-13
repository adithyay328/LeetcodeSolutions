class Solution {
public:
    int lengthOfLastWord(string s) {
      bool isWordDone = false;
      int lengthOfWord = 0;

      int firstLetterIndex = s.size() - 1;
      while(s[firstLetterIndex] == ' ') {
	firstLetterIndex--;
      }
      
      for(int i = firstLetterIndex; i >= 0 && !isWordDone; i--) {
	isWordDone = s[i] == ' ';

	if(!isWordDone) {
	  lengthOfWord++;
	}
      }

      return lengthOfWord;
    }
};
