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

private:
    
    //inorder-value, inorder-index
    unordered_map<int, int> um;
    int index = 0;
public:
    
    TreeNode* getTree(vector<int>& preorder, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        
        //因为前序遍历时，下一个肯定是按顺序来的
        //所以index只要一直加就可以了
        TreeNode *node = new TreeNode(preorder[index++]);
        
        //根据中序来限制左子树
        node->left = getTree(preorder, start, um[node->val] - 1);
        
        //根据中序来限制右子树
        node->right = getTree(preorder, um[node->val] + 1, end);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        //把中序序列的值与位置定下来
        for (int i = 0; i < inorder.size(); ++i)
        {
            um[inorder[i]] = i;
        }
        
        return getTree(preorder, 0, preorder.size() - 1);
    }
    

};