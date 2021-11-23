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
    ListNode* reverseList(ListNode* head) {      
      ListNode* reversedCurr = nullptr;
      
      while(head != nullptr) {
	ListNode* currNode = new ListNode;
	currNode -> val = head -> val;
	
	currNode -> next = reversedCurr;
	reversedCurr = currNode;

	head = head -> next;
      }

      return reversedCurr;
    }
};
