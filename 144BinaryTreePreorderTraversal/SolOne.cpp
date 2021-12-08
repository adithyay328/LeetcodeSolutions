#include <vector>

using std::vector;

/**                                                                                                                                                                                                       
 * Definition for a binary tree node.                                                                                                                                                                     
 * struct TreeNode {                                                                                                                                                                                      
 *     int val;                                                                                                                                                                                           
 *     TreeNode *left;                                                                                                                                                                                    
 *     TreeNode *right;                                                                                                                                                                                   
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}                                                                                                                                               *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}                                                                                                                                         
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}                                                                                                             
 * };                                                                                                                                                                                                      
 */
class Solution {
public:
  void preorderTraversalRecursive(TreeNode* root, vector<int>& sol) {
    sol.push_back(root -> val);

    if(root -> left != nullptr) {
      preorderTraversalRecursive(root -> left, sol);
    }


    if(root -> right != nullptr) {
      preorderTraversalRecursive(root -> right, sol);
    }

  }

  vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> solVec;

    if(root != nullptr) {
      //This is a recursive solution.                                                                                                                                                                      
      preorderTraversalRecursive(root, solVec);
    }

    return solVec;
  }

};
