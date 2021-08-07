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
private:
    int ans = INT_MIN;
public:
    
    
    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        
        int sum = 0;
        int leftMax = helper(root->left);
        int rightMax = helper(root->right);
        
        sum = max(root->val, max(root->val + leftMax, root->val+rightMax));
        
        ans = max(ans, max(sum, root->val + leftMax + rightMax));
        
        return sum;
    }
    
    int maxPathSum(TreeNode* root) {
        
        helper(root);
        return ans;
    }
};