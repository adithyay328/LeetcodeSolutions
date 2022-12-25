# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Do a pre-order traversal of the tree, ignoring nodes
    # that aren't in feasible region
    def rangeSumBST(self, root, low: int, high: int):
        inRange = lambda val: low <= val and val <= high
        sum = 0
        if root is None:
          return 0
        elif inRange(root.val):
          sum += root.val
          print(sum)
        
        if root.left is not None and root.val >= low:
          sum += int(self.rangeSumBST(root.left, low, high))
        
        if root.right is not None and root.val <= high:
          sum += int(self.rangeSumBST(root.right, low, high))
        
        return sum