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
    //Method 1
    /*
    TreeNode* dfs(TreeNode* root)
    {
        
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return root;
        
        if (root->left != nullptr)
        {
            TreeNode *tmp = root->right;
            TreeNode *lf = dfs(root->left);
            root->right = root->left;
            root->left = nullptr;
            lf->left = tmp;
            
        }
        if (root->right != nullptr)
            return dfs(root->right);
        return root;
        
    }
    */
    
    void flatten(TreeNode* root) {
        //Method 1:
        /*
        dfs(root);
        */
        
        //Method 2:
        if (root != nullptr)
        {
            TreeNode *l = root->left;
            TreeNode *r = root->right;
            root->left = nullptr;
            flatten(l);
            flatten(r);
            root->right = l;
            TreeNode *cur = root;
            while (cur->right != nullptr) cur = cur->right;
            cur->right = r;
        }
        
    }
};