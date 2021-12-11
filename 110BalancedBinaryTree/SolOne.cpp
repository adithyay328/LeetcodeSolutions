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
public:
  int getDepthOfTree(TreeNode* root) {
    if(root == nullptr) {
      return 0;
    }
    else {
      return std::max(getDepthOfTree(root -> left) + 1, getDepthOfTree(root -> right) + 1);
    }
  }
  
  bool isBalanced(TreeNode* root) {
    if(root == nullptr) { return true; }
    else {
      bool result = isBalanced(root -> left) && isBalanced(root -> right);
      result = result && std::abs(getDepthOfTree(root -> left) - getDepthOfTree(root -> right)) <= 1;
      return result;
    }
  }
};
