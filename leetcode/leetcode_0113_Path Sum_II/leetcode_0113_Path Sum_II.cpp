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
    
    void dfs(TreeNode* root, vector<vector<int>> &ans, vector<int> &subSet, int &localSum, int &targetSum)
    {
        if (root == nullptr)
            return;
        
        localSum += root->val;
        subSet.push_back(root->val);
        
        if (localSum == targetSum && root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(subSet);
        }
        else
        {
            dfs(root->left, ans, subSet, localSum, targetSum);
            dfs(root->right, ans, subSet, localSum, targetSum);
        }
        
        localSum -= root->val;
        subSet.pop_back();
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> subSet;
        int localSum = 0;
        
        dfs(root, ans, subSet, localSum, targetSum);
        
        return ans;
    }
};