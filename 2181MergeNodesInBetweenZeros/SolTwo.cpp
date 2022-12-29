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
  ListNode* mergeNodes(ListNode* head) {
    ListNode* curr = head;

    // Starting at the zero at the front, delete the next node
    // and add its value to the current node's value. Once you hit
    // a zero node, move curr to there and continue. We stop just
    // before moving to the end of the list, since we want to delete that
    while(curr -> next -> next != nullptr) {
      ListNode* next = curr -> next;

      if(next -> val != 0) {
        // Increment current value with next node's value
        curr -> val += next -> val;

        // Delete next node and re-connect linked list
        curr -> next = next -> next;
        delete next;
      } else {
        // If we found another zero node, move curr to there
        curr = next;
      }
    }

    // We only get here if the next node is the last node in the list,
    // so we need to delete it
    ListNode* end = curr -> next;
    curr -> next = nullptr;

    delete end;

    return head;
  }
};