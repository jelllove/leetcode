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
    bool hasNode(TreeNode* root, TreeNode* seek)
    {
        if (root == NULL)
            return false;
        
        if (root == seek)
            return true;
        else
            return (hasNode(root->left, seek) || hasNode(root->right, seek));
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //Method 1: 遍历去找left和right中是否包含了p和q，好理解，但是时间复杂度高
        /*
        if (hasNode(root->left, p) && hasNode(root->left, q))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (hasNode(root->right, p) && hasNode(root->right, q))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
        */
        //Method 2: 使用回溯法
        if (root == NULL || p == NULL || q == NULL)
            return root;
        
        if (root == p || q == root)
            return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (left == NULL)
        {
            return right;
        }
        else
        {
            if (right == NULL)
                return left;
            else
                return root;
        }
    }
};