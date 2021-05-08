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
    int m_depth = 0;
public:
    
    void helper(TreeNode* root, int level)
    {
        if (root == nullptr)
            return;
        
        m_depth = max(m_depth, level);
        
        helper(root->left, level + 1);
        helper(root->right, level + 1);
    }
    
    int maxDepth(TreeNode* root) {
        //Method 1: using the traditional recursion
        /*
        helper(root, 1);
        return m_depth;
        */
        
        //Method 2: using a very simple recusion;
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};