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
    
    //Method 1: using the recursion
    /*
    int dfs(TreeNode* root, bool &failure)
    {
        if (failure || root == nullptr)
            return 0;
        
        int l = dfs(root->left, failure);
        int r = dfs(root->right, failure);
        
        if (abs(l - r) > 1)
        {
            failure = true;
            return 0;
        }
        
        return max(l, r) + 1;
    }
    */
    
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
            return max(getHeight(root->left), getHeight(root->right)) + 1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        //Method 1: using the recursion
        /*
        bool failure = false;
        dfs(root, failure);
        
        return !failure;
        */
        
        //Method 2: is easy to understadning
        if (root == nullptr)
            return true;
    
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        
        if (abs(l -r) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};