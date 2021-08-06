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
    ListNode *detectCycle(ListNode *head) {
        
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast != nullptr && fast->next != nullptr && slow != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow)
            {
                fast = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                
                return slow;
            }
        }
        
        return nullptr;
    }
};