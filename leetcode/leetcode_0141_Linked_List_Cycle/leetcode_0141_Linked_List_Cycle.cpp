class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *one = head;
        ListNode *two = head;
        
        while (one != NULL && 
               two != NULL &&
               two->next != NULL &&
               two->next->next != NULL
              )
        {
            one = one->next;
            two = two->next->next;
            if (one == two)
            {
                return true;
            }
        }
        
        return false;
    }
};

