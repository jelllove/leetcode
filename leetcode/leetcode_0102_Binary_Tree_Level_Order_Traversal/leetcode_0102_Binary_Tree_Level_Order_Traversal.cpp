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
        vector<vector<int>> ans;
        
        if (root == nullptr)
            return ans;
        
        
        queue<TreeNode *> q;
        q.push(root);
        
        int n = 0;
        while (!q.empty())
        {
            //这里进行pop的时候，只pop出当前的N个，这样的话，就相当于只pop了一层，其实就是一个BFS的算法
            n = q.size();
            
            vector<int> tmpList;
            
            while (n > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                
                tmpList.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
                --n;
            }
            
            ans.push_back(tmpList);
        }
        
        return ans;
        
    }
};