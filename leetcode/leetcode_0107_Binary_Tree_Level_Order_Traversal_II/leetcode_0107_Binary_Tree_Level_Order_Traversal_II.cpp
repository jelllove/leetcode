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
    
    //Method 1:DFS
    void dfs(vector<vector<int>> &ans, int level, TreeNode* root)
    {
        if (root == NULL)
            return;
        
        //先看一下是否当前已经有对应的子队列了，如果没有，就加一个
        if (ans.size() < level)
        {
            ans.push_back(vector<int>());
        }
        
        ans[level - 1].push_back(root->val);
        
        //再找左子树，和右子树，所以这个是一个前序
        dfs(ans, level + 1, root->left);
        dfs(ans, level + 1, root->right);
    }
    
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //Method 1: Using the recursion + DFS
        //利用递归式的前序深度搜索，来找出所有的值，并放到对应的队列中
        /*
        vector<vector<int>> ans;
        
        dfs(ans, 1, root);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        */
        
        
        //Method 2: using the queue，and none recursion.
        //利用一个queue，完成一次BFS，广度搜索
        vector<vector<int>> ans;
        
        if (root == NULL)
            return ans;
        
        //创建一个树的queue
        queue<TreeNode*> q;
        
        //把根结点放进去
        q.push(root);
        
        while (!q.empty())
        {
            vector<int> vec;
            //得到当前的结点个数
            int n = q.size();
            
            //只pop出当前的结点，后来加进来的不动
            for (int i = 0; i < n; ++i)
            {
                //把值放进临时的vector中
                TreeNode *node = q.front();
                vec.push_back(node->val);
                
                //加放它的左右子结点
                if (node->left != NULL)
                    q.push(node->left);
                
                if (node->right != NULL)
                    q.push(node->right);
                
                q.pop();
            }
            
            ans.push_back(vec);
        }
        
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
        
        
    }
};