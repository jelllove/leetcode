/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        if (root == NULL || p == NULL || q == NULL)
            return root;
        
        //如果这两个值都比当前这个ROOT小，说明它们的共同父结点肯定在root的left中
        if (root->val < p->val &&
            root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (root->val > p->val &&
                 root->val > q->val)
        {
            //如果这两个值都比当前这个ROOT大，说明它们的共同父结点肯定在root的right中
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            //其实的情况，比如：
            //p或q有一个是等于root的，那直接返回root
            //q>root, p<root, 或是 q < root, p >root,那也是直接返回root
            return root;
        }
        
    }
};