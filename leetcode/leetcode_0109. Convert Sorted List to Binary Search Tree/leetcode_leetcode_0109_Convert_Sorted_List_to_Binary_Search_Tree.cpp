/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    //Method 1
    TreeNode* helper(vector<int> &data, int l, int r)
    {
        if (l > r)
            return nullptr;
        
        int m = (r - l) / 2 + l;
        
        TreeNode *tmp = new TreeNode(data[m]);
        tmp->left = helper(data, l, m - 1);
        tmp->right = helper(data, m + 1, r);
        
        return tmp;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        //Method 1: traverse the list first
        vector<int> data;
        while (head != nullptr)
        {
            data.push_back(head->val);
            head = head->next;
        }
        
        return helper(data, 0, data.size() - 1);
        
        
    }
};