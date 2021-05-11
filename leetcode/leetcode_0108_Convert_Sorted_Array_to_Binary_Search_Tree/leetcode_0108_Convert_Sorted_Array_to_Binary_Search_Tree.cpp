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
    
    TreeNode* createTree(vector<int>& nums, int from, int to)
    {
        if (from > to)
            return nullptr;
        
        int mid = (from + to) / 2;
        
        TreeNode* tree = new TreeNode(nums[mid]);
               
        tree->left = createTree(nums, from, mid - 1);
        tree->right = createTree(nums, mid + 1, to);
        
        return tree;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return createTree(nums, 0, nums.size() - 1);
    }
};