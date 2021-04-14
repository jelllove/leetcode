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
    
    
    bool helper(TreeNode* root, long minVal, long maxVal)
    {
        if (root == NULL)
            return true;
        
        if (root->val <= minVal || root->val >= maxVal)
            return false;
        
        return (helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal));
    }
    
    void dfs(TreeNode* root, vector<int> &vec)
    {
        if (root == NULL)
            return;
        
        dfs(root->left, vec);
        vec.push_back(root->val);
        dfs(root->right, vec);
    }
    
    bool isValidBST(TreeNode* root) {
        
        //Method 1: DFS+inorder遍历，因为是BST，所以得到的结果应该是一个升序的
        vector<int> vec;
        dfs(root, vec);
        
        for (int i = 0; i < vec.size() - 1; ++i)
        {
            if (vec[i] >= vec[i + 1])
                return false;
        }
        
        return true;
        
        
        //Method 2: 遍历的过程中，把上一层的最大值和最小值都带过去，当成一个新的树来判断
        //return helper(root, LONG_MIN, LONG_MAX);
    }
};