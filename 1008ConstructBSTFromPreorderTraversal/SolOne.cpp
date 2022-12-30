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

#include <vector>
#include <list>

using std::vector;
using std::list;

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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    // Keep track of the root nodes we've passed using a list;
    // then every time we insert, iterate through in reverse to find
    // the appropriate root to insert into
    list<TreeNode*> roots;
    TreeNode* root = new TreeNode(preorder[0]);
    roots.push_back(root);

    TreeNode* curr = root;

    for(int i = 1; i < preorder.size(); i++) {
      // If this value is less than root, then we
      // know we're in the left side of the pre-order
      // traverse of that root; add curr to the list of
      // roots we've accessed, and update curr to the new
      // value
      if(preorder[i] < curr -> val) {
        // Create new tree node and create link from curr root
        TreeNode* newCurr = new TreeNode(preorder[i]);
        curr -> left = newCurr;

        // Throw curr root on our list and update
        roots.push_back(curr);
        curr = newCurr;
      } else {
        // If we enter this else statement, we're now dealing with a
        // node that isn't in the left subtree. This is the more interesting
        // case, where we need to do 2 things in order:
        // 1. Move up the tree, until one of 2 things happen:
        //    a. We find a node that is bigger than our current node;
        //       in this case, we set the current root to its left child
        //    b. If we hit the root, use that as the curr root
        // 2. Start doing a traversal through the tree, until we find a
        //    nullptr where our node should be. Insert our node there

        // Start by iterating backwards through the tree, popping
        // the end of the list into curr until the root is greater
        while(roots.size() > 0 && roots.back() -> val < preorder[i]) {
          // Move one level up in the tree
          curr = roots.back();

          // Remove that root from the list
          roots.pop_back();
        }

        // Now that we have the right curr, start searching for the right
        // place to insert
        while(true) {
          // Push curr onto the list; we're going to move to a child
          // anyway
          roots.push_back(curr);

          // If preorder belongs in the left subtree
          if (curr -> val > preorder[i]) {
            // If a node is already there, move root there
            if (curr -> left != nullptr) {
              curr = curr -> left;
            }
            // Otherwise, insert there
            else {
              TreeNode* newNode = new TreeNode(preorder[i]);
              curr -> left = newNode;

              curr = newNode;
              break;
            }
          } 
          // If preorder belongs in the right subtree
          else {
            // If a node is already there, move root there
            if (curr -> right != nullptr) {
              curr = curr -> right;
            }
            // Otherwise, insert there
            else {
              TreeNode* newNode = new TreeNode(preorder[i]);
              curr -> right = newNode;

              curr = newNode;
              break;
            }
          }
        }
      }
    }

    return root;    
  }
};