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

struct Compare
{
        bool operator () (ListNode* a, ListNode* b)
        {
            return a->val >= b->val;
        }
};

class Solution {
    
    
    
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        
        //Method 1: Using the min heap, but it is not efficiency 
        priority_queue<ListNode*, vector<ListNode *>, Compare> que;
        
        while (head != nullptr)
        {
            que.push(head);
            head = head->next;
        }
        
        ListNode tmp;
        ListNode *tail = &tmp;
        
        while (!que.empty())
        {
            tail->next = que.top();
            que.pop();
            tail = tail->next;
            tail->next = nullptr;
        }
        
        return tmp.next;
        
    }
};