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

    //Method 1: using the DFS, and record the data into a vector.
    /*
    void helper(TreeNode *root, int level, vector<vector<int>> &data)
    {
        if (root == nullptr)
            return;
    
        if (data.size() < level)
        {
            data.push_back(vector<int>{root->val});
        }
        else
        {
            data[level - 1].push_back(root->val);
        }
        helper(root->left, level + 1, data);
        helper(root->right, level + 1, data);
    }
    
    int getSum(TreeNode* root)
    {
        vector<vector<int>> ans;
        helper(root, 1, ans);

        if (ans.size() == 0)
            return 0;

        int sum = 0;
        for (auto &it : ans[ans.size() - 1])
        {
            sum += it;
        }

        return sum;
    }
    */
    
    
    //Method 2: using the DFS, and record the data into a vector.
    void getSum(TreeNode* root, int level, int &sum, int &maxLevel)
    {
        if (root == nullptr)
            return;

        if (level > maxLevel)
        {
            sum = root->val;
            maxLevel = level;
        }
        else if (level == maxLevel)
        {
            sum += root->val;
        }
        
        getSum(root->left, level + 1, sum, maxLevel);
        getSum(root->right, level + 1, sum, maxLevel);
    }
    
    
    int bfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        int sum = 0;
        while (!q.empty())
        {
            int n = q.size();
            sum = 0;
            for (int i = 0; i < n; ++i)
            {
                TreeNode *topTree = q.front();
                sum += topTree->val;
                
                if (topTree->left != nullptr)
                    q.push(topTree->left);
                if (topTree->right != nullptr)
                    q.push(topTree->right);
                
                q.pop();
            }
        }
        
        return sum;
        
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
    
        //Method 1: DFS, record the data
        //return getSum(root);
        
        //Method 2: DFS, only record the max level and the sum value
        /*
        int sum = 0;
        int maxLevel = 0;
        getSum(root, 0, sum, maxLevel);
        return sum;
        */
        
        //Method 3: BFS
        return bfs(root);
    }
};