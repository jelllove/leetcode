
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        //Method 1: using the pointer to traverse
        if (head == nullptr ||  head->next == nullptr)
            return head;
        
        ListNode ret(INT_MIN);
        ListNode *tail = &ret;
        
        while (head != nullptr)
        {
            if (head->val != tail->val)
            {
                tail->next = head;
                tail = head;
            }
            
            head = head->next;
        }
        
        tail->next = nullptr;
        return ret.next;
    }
};