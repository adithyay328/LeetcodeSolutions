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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      //If the last sum was greater than 9, this sum will equal 1. The next place will have to add this on.
      int carried = 0;

      ListNode* resultHead = new ListNode;
      ListNode* resultCurr = resultHead;

      ListNode* l1Curr = l1;
      ListNode* l2Curr = l2;


      //In the last iteration, a new node is added to the result but it's empty.
      //To remedy this, we're just going to store the previous pointer here,
      //and after the loop is finished, remove the last element
      ListNode* lastActualNode = resultHead;
      
      while(l1Curr != nullptr and l2Curr != nullptr) {
	int sum = l1Curr -> val + l2Curr -> val + carried;

	if(carried != 0) { carried--; }
	
	if(sum > 9) {
	  carried++;
	  sum -= 10;
	}

	lastActualNode = resultCurr;
	
	resultCurr -> val = sum;
	ListNode* newNode = new ListNode;
	resultCurr -> next = newNode;
	resultCurr = newNode;

	l1Curr = l1Curr -> next;
	l2Curr = l2Curr -> next;
      }

      //We need to deal with the special case that one of the lists is longer than the other. In that case, we simply add carried to the remaining values in the longer list.
      while(l1Curr != nullptr) {
	int sum = l1Curr -> val + carried;

	if(carried != 0) { carried--; }

	if(sum > 9) {
	  carried++;
	  sum -= 10;
	}

	lastActualNode = resultCurr;

	resultCurr -> val = sum;
	ListNode* newNode = new ListNode;
	resultCurr -> next = newNode;
	resultCurr = newNode;

	l1Curr = l1Curr -> next;
      }

      while(l2Curr != nullptr) {
	int sum	= l2Curr -> val	+ carried;

	if(carried != 0) { carried--; }

        if(sum > 9) {
          carried++;
          sum -= 10;
        }

        lastActualNode = resultCurr;

        resultCurr -> val = sum;
        ListNode* newNode = new	ListNode;
        resultCurr -> next = newNode;
        resultCurr = newNode;

        l2Curr = l2Curr	-> next;
      }
      
      if(carried == 0) {
	delete lastActualNode -> next;
	lastActualNode -> next = nullptr;
      }
      else {
	resultCurr -> val = carried;
      }

      return resultHead;
    }
};
