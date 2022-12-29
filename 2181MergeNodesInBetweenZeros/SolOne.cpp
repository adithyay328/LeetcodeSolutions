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
 #include <iostream>

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
      // Keeping track of where the zeros started
      ListNode* zeroStart = head;
      int currSum = 0;

      // Iterating over the list, keeping track of where we're seeing zeros
      for(ListNode* curr = head; curr != nullptr; curr = curr -> next) {
        std::cout << curr -> val << std::endl;

        if(curr -> val != 0) {
          currSum += curr -> val;
        } else if(curr -> next != nullptr) {
          // Delete all but one node in between the zeros

          for(ListNode* inBtw = zeroStart -> next; inBtw -> next -> val != 0; inBtw = inBtw) {
            ListNode* next = inBtw -> next;
            inBtw -> next = next -> next;
            delete next;
          }

          // Update next node's sum
          zeroStart -> next -> val = currSum;

          // Reset zero pointers and sum
          zeroStart = curr;
          currSum = 0;
        }
      }

      return head;
    }
};