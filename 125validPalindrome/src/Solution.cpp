#include <iostream>
#include <cctype>
#include <string>

using std::string;

class Solution {
public:
    char lowerCase(char c) {
        if(isalpha(c)) {
            c = std::tolower(c);
        }
        return c;
    }
    
    bool isPalindrome(string s) {
//         std::string alphaOnly = "";
        
//         for(int i = 0; i < s.size(); i++) {
//             if(isalnum(s[i])) {
//                 if(isalpha(s[i])) {
//                     alphaOnly += std::tolower(s[i]);
//                 }
//                 else {
//                     alphaOnly += s[i];
//                 }
                
//             }
//         }
            
//         std::string alphaReversed = "";
//         for(int i = alphaOnly.size() - 1; i >= 0; i--) {
//             alphaReversed += alphaOnly[i];
//         }
        
//         return alphaOnly.compare(alphaReversed) == 0;
        int aIndex = 0;
        int bIndex = s.size() -1;
        
        char a = s.at(aIndex);
        char b = s.at(bIndex);
        
        while(aIndex != s.size() && bIndex != -1) {
            a = s.at(aIndex);
            b = s.at(bIndex);
            
            if(isalnum(a) && isalnum(b)) {
                a = lowerCase(a);
                b = lowerCase(b);
                
                if(a != b) {
                    std::cout << a << aIndex << std::endl;
                    std::cout << b << bIndex << std::endl;
                    return false;
                }
                
                aIndex++;
                bIndex--;
            }
            
            else {
                while(aIndex < s.size() - 1 && !isalnum(a)) {
                    aIndex++;
                    a = s.at(aIndex);
                }  
                while(bIndex > 0 && !isalnum(b)) {
                    bIndex--;
                    b = s.at(bIndex);
                } 
                
                
                if(!isalnum(a) || !isalnum(b)) {
                    break;
                }
            }
            
            
        }
        
        return true;
    }
};


int main() {
    Solution mySol;

    bool a = mySol.isPalindrome(" ");
    std::cout << a << std::endl;

}