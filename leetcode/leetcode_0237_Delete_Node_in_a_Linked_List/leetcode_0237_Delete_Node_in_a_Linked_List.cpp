/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //这个其实不可能真的删除自己的，只能是把它的下一个NODE的值拿过来，然后给自己，然后把它下一个删除，来模拟删除自己
        ListNode *storeNext = node->next;
        node->next = storeNext->next;
        node->val = storeNext->val;
        delete storeNext;
    }
};