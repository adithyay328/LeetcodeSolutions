#include <string>
#include <list>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::list<char> charList;
        for(int i = 0; i < s.length(); i++) {
            char current = s.at(i);

            if( current == '(' || current == '[' || current == '{' ) {
                charList.push_back(current);
            }

            else {
                bool isAValidBrace = false;
                if ( charList.back() == '(' && current == ')' ) {
                    isAValidBrace = true;
                }
                else if ( charList.back() == '{' && current == '}' ) {
                    isAValidBrace = true;
                }
                else if ( charList.back() == '[' && current == ']' ) {
                    isAValidBrace = true;
                }

                if ( isAValidBrace ) {
                    std::cout << "Popping" << std::endl;
                    charList.pop_back();
                }

                else {
                    std::cout << isAValidBrace << std::endl;
                    std::cout << current << std::endl;
                    std::cout << charList.back() << std::endl;

                    isAValidBrace = ( charList.back() == '[' && current == ']' );
                    std::cout << isAValidBrace << std::endl;
                    return false;
                }
            }
        }

        return ( charList.size() == 0 );
    }
};

int main() {
    Solution mySol;;
    bool result = mySol.isValid( "(){}" );

    if (result) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }
}