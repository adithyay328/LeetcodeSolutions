# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
    """
    To implement this, should be really easy;
    for any node, remove successors which
    are equal to the current.

    UPDATE: Not that simple. We need to delete
    ALL DUPLICATES, leaving only non-duplicate elements.

    "best" way to do it: delete all elements that are duplicate
    easiest way to do it: just make a new element with non-duplicates
    """
    
    returnList = None
    returnListTail = returnList

    while head is not None:
      # If head's successor doesn't contain the same
      # value, copy to return list and increment head
      if head.next is None or head.next.val != head.val:
        if returnList is None:
          returnList = ListNode(val=head.val)
          returnListTail = returnList
        else:
          returnListTail.next = ListNode(val=head.val)
          returnListTail = returnListTail.next
        head = head.next
      
      # If this isn't true, head's successor has the same
      # value. In that case, keep looping and skip all
      # nodes of the same value
      else:
        badVal = head.val
        while head is not None and head.val == badVal:
          head = head.next
     
    return returnList
