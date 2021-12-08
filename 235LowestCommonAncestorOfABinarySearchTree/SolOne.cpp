#include <unordered_set>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      std::unordered_set<TreeNode*> ancestorsOfP;

      TreeNode* currentNodeInSearch = root;

      //Dumping all ancestors of p into a hash map for quick search
      while(currentNodeInSearch != nullptr) {
	ancestorsOfP.insert(currentNodeInSearch);

	if(currentNodeInSearch == p) { break; }
	
	if(currentNodeInSearch -> val > p -> val) {
	  currentNodeInSearch = currentNodeInSearch -> left;
	}
	else {
	  currentNodeInSearch = currentNodeInSearch -> right;
	}
      }

      //Searching all ancestors of q to find commons
      TreeNode* commonA = root;
      currentNodeInSearch = root;

	while(currentNodeInSearch != nullptr) {
	  if(ancestorsOfP.count(currentNodeInSearch) == 1) { commonA = currentNodeInSearch; }

	  if(currentNodeInSearch == q) { break;  }
	  
	  if(currentNodeInSearch -> val > q -> val) {
	    currentNodeInSearch = currentNodeInSearch -> left;
	  }
	  else {
	    currentNodeInSearch = currentNodeInSearch -> right;
	  }
	}
	
	return commonA;
    }
};
