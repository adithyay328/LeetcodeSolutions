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

                                                                                                                                                                                                        
// Definition for singly-linked list.                                                                                                                                                                      
 struct ListNode {                                                                                                                                                                                       
   int val;                                                                                                                                                                                            
   ListNode *next;                                                                                                                                                                                     
   ListNode() : val(0), next(nullptr) {}                                                                                                                                                               
   ListNode(int x) : val(x), next(nullptr) {}                                                                                                                                                          
   ListNode(int x, ListNode *next) : val(x), next(next) {}                                                                                                                                             
  };                                                                                                                                                                                                      


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* origHead = head;

      if(head == nullptr) {
	return head;
      }
      
      ListNode* next = head -> next;

      while(next != nullptr) {
	if(head -> val == next -> val) {
	  next = next -> next;
	  delete head -> next;
	  head -> next = next;
	}

	else {
	  if(next != nullptr) {
	    head = next;
	    next = next -> next;
	  }
	}
      }

      return origHead;
    }
};
