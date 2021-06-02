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
    ListNode* deleteDuplicates(ListNode* head) {
        
        //Method 1: using two pointer
        /*
        ListNode ret(INT_MIN);
        ListNode *tail = &ret;
        
        while (head != nullptr && head->next != nullptr)
        {
            if (head->val == head->next->val)
            {
                ListNode *tmp = head->next;
                while (tmp->next != nullptr && tmp->next->val == head->val)
                    tmp = tmp->next;
                
                head = tmp->next;
            }
            else
            {
                tail->next = head;
                tail = tail->next;
                head = head->next;
            }
        }
        
        tail->next = head;
        
        return ret.next;
        */
        
        //Method 2: using the recursion
        if (head == nullptr || head->next == nullptr)
            return head;
        
        
        bool flag = false;
        
        ListNode *tmpNext = head->next;
        
        while (tmpNext != nullptr && tmpNext->val == head->val)
        {
            flag = true;
            tmpNext = tmpNext->next;
        }
        
        if (flag)
        {
            return deleteDuplicates(tmpNext);
        }
        else
        {
            head->next = deleteDuplicates(tmpNext);
            return head;
        }
    }
};