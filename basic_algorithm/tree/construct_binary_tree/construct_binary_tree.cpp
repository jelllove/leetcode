#include "../../../include/public.h"


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* getNode(vector<int>& preorder, int l, int r, int &idx, unordered_map<int, int> &hash)
    {
       if (l > r)
           return nullptr;
        
        int val = preorder[idx++];
        TreeNode *newNode = new TreeNode(val);
        
        newNode->left = getNode(preorder, l, hash[val] - 1, idx, hash);
        newNode->right = getNode(preorder, hash[val] + 1, r, idx, hash);
        
        return newNode;
    }
    
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        unordered_map<int, int> hash;
        for (int i = 0; i < inorder.size(); ++i)
        {
            hash[inorder[i]] = i;
        }
        int idx = 0;
        return getNode(preorder, 0, preorder.size() - 1, idx, hash);
        
    }
};


int main()
{
    /*
    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]
    */

    TreeNode *node = Solution().buildTree({3,9,20,15,7}, {9,3,15,20,7});

    return 0;
}