# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    # To remove node, we need to know its pre-decessor node(if one),
    # and apply the delete operator to that

    # So actually, problem is like this:
    # 1. Determine node before the target 
    #    node(could be before the start
    #    of the list)
    # 2. Delete it
    prev = ListNode(val=None)
    prev.next = head

    origPrev = prev

    ahead = head
    for i in range(n):
      ahead = ahead.next
    
    while ahead != None:
      ahead = ahead.next
      prev = prev.next

    # Deletion step
    prev.next = prev.next.next

    # Return
    return origPrev.next
