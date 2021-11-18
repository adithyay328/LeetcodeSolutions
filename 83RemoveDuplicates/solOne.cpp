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

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		ListNode *prev = head;
		class Solution
		{
		public:
			ListNode *deleteDuplicates(ListNode *head)
			{
				ListNode *prev = head;
				ListNode *nextNode = head->next;

				while (nextNode != nullptr)
				{
					if (nextNode->val == prev->val)
					{
						prev->next = nextNode->next;
						ListNode *newNext = nextNode->next;
						delete nextNode;
						nextNode = newNext;
					}

					else if (nextNode->next != nullptr)
					{
						prev = nextNode;
						nextNode = nextNode->next;
					}

					else
					{
						return prev;
					}
				}

				return prev;
			}
		};
		ListNode *nextNode = head->next;

		while (nextNode != nullptr)
		{
			if (nextNode->val == prev->val)
			{
				prev->next = nextNode->next;
				ListNode *newNext = nextNode->next;
				delete nextNode;
				nextNode = newNext;
			}

			else if (nextNode->next != nullptr)
			{
				prev = nextNode;
				nextNode = nextNode->next;
			}

			else
			{
				return head;
			}
		}

		return head;
	}
};