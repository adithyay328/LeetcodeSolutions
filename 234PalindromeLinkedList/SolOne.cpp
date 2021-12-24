#include <iostream>

using std::cout;
using std::endl;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        double sum = 0.0;
        int len = 0;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            len++;
            curr = curr -> next;
        }
        
        curr = head;
        int rawSum = 0;
        long firstSum = 0;
        long secondSum = 0;
        int i = 0;
        
        for(int x = 0; i < len / 2; i++) {
            firstSum += curr -> val * (i + 1); 
            rawSum += curr -> val;
            curr = curr -> next;
        }

        if(len % 2 == 1) {
            curr = curr -> next;
        }

        for(int x = 0; i > 0; i--) {
            secondSum += curr -> val * i;
            rawSum -= curr -> val;
            curr = curr -> next;
        }
        cout << firstSum << endl;
        cout << secondSum << endl;
        cout << len << endl;
        cout << rawSum << endl;

        return firstSum == secondSum && rawSum == 0;;
    }
};
