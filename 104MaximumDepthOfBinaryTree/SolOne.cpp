#include <algorithm>

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
    int maxDepth(TreeNode* root) {
      if(root == nullptr) { return 0; }
      
      //This is going to be a recursive solution. Basically, keep going until
      //both child nodes are null, at which point your return 0.
      //If both child nodes are not null, call maxDepth on all non-null child nodes,
      //and return the maximum of the 2 responses from each child node.
      if(root -> left == nullptr && root -> right == nullptr) {
	return 1;
      }
      
      else if(root -> left != nullptr && root -> right != nullptr) {
	return std::max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
      }
      
      else if(root -> left != nullptr) {
	return maxDepth(root -> left) + 1;
      }
      
      else if(root -> right != nullptr) {
	return maxDepth(root -> right) + 1;
      }

      else {
	return 1;
      }
    }
};
