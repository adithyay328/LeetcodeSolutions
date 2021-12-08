#include <cstdlib>
#include <cmath>

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
  TreeNode* sortedArrayToBSTRecursive(vector<int>& nums, int lowIndex, int highIndex) {
    int mid = (int)(( lowIndex + highIndex) / 2.0 );
    TreeNode* result = new TreeNode;
    TreeNode* leftNode = new TreeNode;
    TreeNode* rightNode = new TreeNode;
    
    int widthOfRange = std::abs(lowIndex - highIndex);
    switch(widthOfRange) {
    case 0:
      result -> val = nums[lowIndex];
      break;
    case 1:
      result -> val = nums[highIndex];
      
      leftNode -> val = nums[lowIndex];
      result -> left = leftNode;
      break;
    case 2:
      result ->	val = nums[highIndex - 1];

      leftNode -> val =	nums[lowIndex];
      result ->	left = leftNode;

      rightNode -> val = nums[highIndex];
      result -> right = rightNode;
      break;
    default:
      result ->	val = nums[mid];
      result -> left = sortedArrayToBSTRecursive(nums, lowIndex, mid - 1);
      result -> right = sortedArrayToBSTRecursive(nums, mid + 1, highIndex);
      break;
    } 
    
    return result;
    
  }
  
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTRecursive(nums, 0, nums.size() - 1);
  }
};
