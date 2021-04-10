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
        
        if (head == NULL)
            return NULL;
        
        ListNode *one = head;
        ListNode *two = head;
        
        while (true)
        {
            one = one->next;
            if (one == NULL)
                return NULL;
            
            
            two = two->next;
            if (two == NULL)
                return NULL;
            
            two = two->next;
            if (two == NULL)
                return NULL;
            
            if (one == two)
            {
                break;
            }
        }
        
        two = head;
        while (one != two)
        {
            one = one->next;
            two = two->next;
        }
            
        return one;
    }
};