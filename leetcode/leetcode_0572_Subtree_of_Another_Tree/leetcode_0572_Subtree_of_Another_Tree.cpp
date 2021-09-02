class Solution {
public:
    bool isSubtreeUtil(TreeNode* r,TreeNode* s)
    {
    if(r==NULL&&s==NULL) return true;
    if(r==NULL||s==NULL) return false;
    return (r->val==s->val)&&isSubtreeUtil(r->left,s->left)&&isSubtreeUtil(r->right,s->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root==NULL) return false;
    if(root->val==subRoot->val) 
    {
    if(isSubtreeUtil(root,subRoot)) return true;
    }
    return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};