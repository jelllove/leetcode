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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (root == nullptr)
            return ans;
        
        
        queue<TreeNode *> q;
        q.push(root);
        
        int n = 0;
        bool direct = 0;
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
            
            if (direct == 1)//因为要求是Z字的顺序，所以一会儿要正向，一会儿要反向
                std::reverse(tmpList.begin(), tmpList.end());
            ans.push_back(tmpList);
            direct ^= 0x1;//这样做一下异或的操作，就会在0和1之间进行切换了
        }
        
        return ans;
    }
};