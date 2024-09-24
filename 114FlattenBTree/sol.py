# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import Tuple

def r_flatten(root : Optional[TreeNode], ) -> Tuple[Optional[TreeNode], Optional[TreeNode]]:
  """
  The recursive flatten function that actually solves this.
  """
  if root is None:
    return None, None
 
  chainStart = root
  chainEnd = root

  # If not None, start by flattening the right tree,
  # then left tree if they exist
  r_chain_start, r_chain_end = r_flatten(root.right)
  l_chain_start, l_chain_end = r_flatten(root.left)

  # Before going forward, update
  # chain end based on if we have
  # a left or right chain
  if r_chain_end is not None:
    chainEnd = r_chain_end
  elif l_chain_end is not None:
    chainEnd = l_chain_end

  # Insert left chain between root and right chain
  if l_chain_start is not None:
    # Insert in between this node and
    # the right tree
    root.right = l_chain_start
    root.left = None

    l_chain_end.right = r_chain_start

  return chainStart, chainEnd

class Solution:
  def flatten(self, root: Optional[TreeNode]) -> None:
    """
    Do not return anything, modify root in-place instead.
    """

    """
    My hunch here is that we can do a reverse
    iteration through it, starting at the very
    end of the tree(rightmost), and slowly
    adding nodes back to the root on the rightmost
    chain.
    """
    root, _ = r_flatten(root)
