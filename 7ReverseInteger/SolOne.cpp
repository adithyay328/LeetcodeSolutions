#include <string>
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0;

	std::string xAsS = std::to_string(x);
	std::string rString;

	if(negative) { rString += '-'; }

	for(int i = xAsS.length() - 1; i >= 0; i--) {
	  rString += xAsS[i];
	}

	try {
	  return std::stoi(rString);
	}
	catch(...) {
	  return 0;
	};
    }
};


int main() {
  Solution mySol;
  std::cout << mySol.reverse(123) << std::endl; 
};
