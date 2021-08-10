class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (low <= root->val and root->val <= high){
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        else if (root->val < low){
            root->left = nullptr;
            root = trimBST(root->right, low, high);
        }
        else {
            root->right = nullptr;
            root = trimBST(root->left, low, high);
        }
        return root;
    }
};