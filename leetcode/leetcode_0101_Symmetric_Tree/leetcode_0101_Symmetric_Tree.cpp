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
    
    bool isMirrorTree(TreeNode* nodeA, TreeNode* nodeB)
    {
        //如果都是空的话，那就直接成功
        if (nodeA == nullptr && nodeB == nullptr)
            return true;
        //一空一非，那就直接失败
        else if (nodeA == nullptr || nodeB == nullptr)
            return false;
        //值不相等，直接返回失败
        else if (nodeA->val != nodeB->val)
            return false;
        else
            //再判断它们的左右子树
            return (isMirrorTree(nodeA->left, nodeB->right) && isMirrorTree(nodeA->right, nodeB->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isMirrorTree(root->left, root->right);
    }
};