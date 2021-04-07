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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        //如果是空链表，或是只有一个结点的话，那直接返回
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *cur = NULL;
        
        while (head != NULL)
        {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = cur;
            cur = tmp;
        }
        
        return cur;
        
    }
};