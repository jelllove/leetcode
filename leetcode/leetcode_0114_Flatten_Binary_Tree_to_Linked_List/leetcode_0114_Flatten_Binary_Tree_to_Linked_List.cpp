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
            //先记录下左右子树
            TreeNode *l = root->left;
            TreeNode *r = root->right;
            
            //然后让左边设置为空
            root->left = nullptr;
            //再把左边捋直
            flatten(l);
            //同时把右边捋直
            flatten(r);
            //然后刚才光头的那个ROOT的右边指向刚才它的左边
            root->right = l;
            
            //然后找到刚才左边的最后一个结点
            TreeNode *cur = root;
            while (cur->right != nullptr) cur = cur->right;
            
            //让刚才的最后一个结点指向刚才右边的
            cur->right = r;
        }
        
    }
};