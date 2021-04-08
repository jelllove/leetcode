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
    
    void helper_break(TreeNode *root, int &index, int k, int &ans, bool &found)
    {
        if (root == NULL || found)
            return;
        
        
        helper_break(root->left, index, k, ans, found);
        ++index;
        if (index == k)
        {
            found = true;
            ans = root->val;
            return;
        }
        helper_break(root->right, index, k, ans, found);
    }
    
    
    void helper_vector(TreeNode *root, vector<int> &vecVal)
    {
        if (root == NULL)
            return;
        
        vecVal.push_back(root->val);
        helper_vector(root->left, vecVal);
        helper_vector(root->right, vecVal);
    }
    
    void helper_heap(TreeNode *root, priority_queue<int, vector<int>, greater<int>> &pq)
    {
        if (root == NULL)
            return;
        
        pq.push(root->val);
        helper_heap(root->left, pq);
        helper_heap(root->right, pq);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        
        if (root == NULL || k <= 0)
            return -1;
        
        
        //Method 1: Traverse the tree with DFS, and sort the result, and find the Kth small value
        /*
        vector<int> treeNodeValue;
        helper_vector(root, treeNodeValue);
        
        std::sort(treeNodeValue.begin(), treeNodeValue.end(), less<int>());
        return treeNodeValue[k - 1];
        */
        
        
        //Method 2: using the min-heap
        /*
        priority_queue<int, vector<int>, greater<int>> pq;
        helper_heap(root, pq);
        
        while (k >= 2)
        {
            pq.pop();
            --k;
        }
        
        return pq.top();
        */
        
        //Method 3: direct break during the traverse
        int index = 0;
        int ans = 0;
        bool found = false;
        helper_break(root, index, k, ans, found);
        
        return ans;
    }
};