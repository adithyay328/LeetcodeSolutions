#include <unordered_set>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      std::unordered_set<ListNode*> nodeMap;
      
      while(headA != nullptr) {
	nodeMap.insert( { headA  }  );

	headA = headA -> next;
      }

      while(headB != nullptr) {
	if(nodeMap.count(headB) != 0) {
	  return headB;
	}

	headB = headB -> next;
      }

      return nullptr;
    }
};
