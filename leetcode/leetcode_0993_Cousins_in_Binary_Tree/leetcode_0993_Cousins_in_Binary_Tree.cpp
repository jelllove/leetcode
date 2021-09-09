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
    int left_level = 0;
    int right_level = 0;
    
    bool leftFound = false;
    bool rightFound = false;
    
    TreeNode *leftParent = nullptr;
    TreeNode *rightParent = nullptr;

    
public:
    
    void findChild(TreeNode* root, TreeNode* parent, int x, int y, int level)
    {
        if (root == nullptr)
            return;
        
        if (root->val == x)
        {
            left_level = level;
            leftParent = parent;
            leftFound = true;
        }
        
        if (root->val == y)
        {
            right_level = level;
            rightParent = parent;
            rightFound = true;
        }
        
        if (!leftFound || !rightFound)
        {
            findChild(root->left, root, x, y, level + 1);
            findChild(root->right, root, x, y, level + 1);
        }
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        findChild(root, nullptr, x, y, 0);
        if (left_level == right_level && leftParent != rightParent && leftFound && rightFound)
            return true;
        else
            return false;
    }
};