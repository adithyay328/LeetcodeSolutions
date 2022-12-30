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

using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  
class Solution {
private:
  // Returns the index of the maximal element in a vector in a given slice
  int maxIndex(vector<int>& nums, int lowerBound, int upperBound) {
    int maxIdx = lowerBound;
    int maxVal = nums[lowerBound];

    for(int i = lowerBound + 1; i < upperBound; i++) {
      if (nums[i] > maxVal) {
        maxIdx = i;
        maxVal = nums[i];
      }
    }

    return maxIdx;
  }

  TreeNode* maximumBinaryTreeRecursive(vector<int>& nums, int lowerBound, int upperBound) {
    // Base case
    if(lowerBound >= upperBound) {
      return nullptr;
    } else {
      // Start by finding maximal index
      int maxIdx = maxIndex(nums, lowerBound, upperBound);

      // Construct our result root
      TreeNode* resultRoot = new TreeNode(nums[maxIdx]);

      // Recursively solve for our left and right nodes
      resultRoot -> left = maximumBinaryTreeRecursive(nums, lowerBound, maxIdx);
      resultRoot -> right = maximumBinaryTreeRecursive(nums, maxIdx + 1, upperBound);

      return resultRoot;
    }
  }
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return maximumBinaryTreeRecursive(nums, 0, nums.size());
  }
};