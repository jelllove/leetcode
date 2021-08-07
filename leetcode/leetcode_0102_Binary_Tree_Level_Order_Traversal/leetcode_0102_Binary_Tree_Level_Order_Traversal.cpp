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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        queue<TreeNode *> q;
        q.push(root);
        
        vector<vector<int>> ans;
            
        while (!q.empty())
        {
            int n = q.size();
            vector<int> subSet;
            for (int i = 0; i < n; ++i)
            {
                TreeNode *topNode = q.front();
                q.pop();
                subSet.push_back(topNode->val);
                
                if (topNode->left != nullptr)
                    q.push(topNode->left);
                
                if (topNode->right != nullptr)
                    q.push(topNode->right);
            }
            
            ans.push_back(subSet);
        }
        
        return ans;
    }
};