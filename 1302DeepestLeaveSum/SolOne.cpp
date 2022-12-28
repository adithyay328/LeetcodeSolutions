/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
  int maxDepth = 0, currSum = 0;

  void recursiveDeepestLeaves(TreeNode* currRoot, int depth) {
    // Since we're looking for the deepest, do an in-order traversal,
    // ignoring the root unless both children are null, since
    // if not it's not a leaf
    if (currRoot -> left != nullptr) {
      recursiveDeepestLeaves(currRoot -> left, depth + 1);
    } 
    if (currRoot -> right != nullptr) {
      recursiveDeepestLeaves(currRoot -> right, depth + 1);
    } 
    if (currRoot -> left == nullptr && currRoot -> right == nullptr) {
      if(depth == maxDepth) {

        currSum += currRoot -> val;
      } else if (maxDepth < depth) {

        maxDepth = depth;
        currSum = currRoot -> val;
      }
    }
  }

public:
  int deepestLeavesSum(TreeNode* root) {
    recursiveDeepestLeaves(root, 0);

    return currSum;
  }
};