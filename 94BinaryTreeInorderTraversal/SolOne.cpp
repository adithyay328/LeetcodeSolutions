#include <vector>

using std::vector;

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
  void inorderTraversalRecursive(TreeNode* root, vector<int>& sol) {
    if(root -> left != nullptr) {
      inorderTraversalRecursive(root -> left, sol);
    }

    sol.push_back(root -> val);

    if(root -> right != nullptr) {
      inorderTraversalRecursive(root -> right, sol);
    }
    
  }
  
  vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> solVec;

    if(root != nullptr) {
      //This is a recursive solution.
      inorderTraversalRecursive(root, solVec);
    }
    
    return solVec;
  }
  
};
