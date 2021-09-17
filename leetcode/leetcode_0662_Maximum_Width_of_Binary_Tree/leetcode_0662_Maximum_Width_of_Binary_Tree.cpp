class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        
        int maxWidth = 0;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            int qLen = q.size();
            unsigned long long minIdx = ULLONG_MAX, maxIdx = 0;
            
            for (int i = 0; i < qLen; ++i) {
                TreeNode *node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();
                
                minIdx = min(minIdx, index);
                maxIdx = max(maxIdx, index);
                
                if (node->left != nullptr) {
                    q.push(make_pair(node->left, 2 * index));
                }
                if (node->right != nullptr) {
                    q.push(make_pair(node->right, 2 * index + 1));
                }
            } // end of for-loop
            
            maxWidth = max(maxWidth, static_cast<int>(maxIdx - minIdx + 1));
        } // end while-loop
        
        return maxWidth;
    }
};