// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool isMirror(TreeNode* aRoot, TreeNode* bRoot) {
        if(aRoot == nullptr && bRoot == nullptr) { return true; }
        else if(aRoot == nullptr || bRoot == nullptr) { return false; }
        else {
            // First checking that roots are the same
            bool result = aRoot -> val == bRoot -> val;

            // Then, going to run this same operation on all subnodes
            result = result && isMirror(aRoot -> left, bRoot -> right) && isMirror(aRoot -> right, bRoot -> left);

            return result;
        }
    };

    bool isSymmetric(TreeNode* root) {
        return isMirror(root -> left, root -> right);
    };
};