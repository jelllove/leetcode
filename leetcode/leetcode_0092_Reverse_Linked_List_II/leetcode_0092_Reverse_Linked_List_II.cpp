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
    pair<ListNode*, ListNode*> reverseNodes(ListNode* head, int n)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        
        while (n > 0)
        {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            --n;
        }
        
        return {prev, cur};
    }
        
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right)
            return head;
        
        //Method 1: just using the link reverse.
        ListNode tmp;
        tmp.next = head;
        ListNode *prev = &tmp;
        
        for (int i = 1; i < left; ++i)
        {
            prev = head;
            head = head->next;
        }
            
        
        pair<ListNode*, ListNode*> ret = reverseNodes(head, right - left + 1);
        
        
        prev->next = ret.first;
        
        while (prev->next != nullptr)
            prev = prev->next;
        
        prev->next = ret.second;
        
        return tmp.next;
    }
};