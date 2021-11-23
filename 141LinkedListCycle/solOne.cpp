/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode* slow = head;
      ListNode* fast = head;

      while(fast != nullptr) {
	slow = slow -> next;
	for(int i = 0; i < 2; i++) {
	  if(fast == nullptr) { return false; }
	  else {
	    fast = fast -> next;
	    if(fast == nullptr) { return false; }
	  }
	}

	if(fast == slow || fast -> next == slow) { return true; }
      }

      return false;
    }
};
