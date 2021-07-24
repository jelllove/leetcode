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
    
    ListNode *reverseList(ListNode *start, ListNode *end)
    {
        ListNode *prev = start;
        ListNode *tail = start->next;
        prev->next = nullptr;
        while (tail != end)
        {
            ListNode *tmp = tail->next;
            tail->next = prev;
            prev = tail;
            tail  = tmp;
        }
        
        tail->next = prev;
        prev = tail;
        
        return prev;
        
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;
        
        //Method 1: go thorugh and store in the vector
        /*
        vector<ListNode *> vec;
        while (head != nullptr)
        {
            vec.push_back(head);
            head = head->next;
        }
        
        int i = 0;
        while (i < vec.size() && i + k <= vec.size())
        {
            reverse(vec.begin() + i, vec.begin() + i + k);
            i += k;
        }
        
        ListNode ans;
        ListNode *tail = &ans;
        
        i = 0;
        while (i < vec.size())
        {
            tail->next = vec[i];
            tail = tail->next;
            tail->next = nullptr;
            ++i;
        }
        
        return ans.next;
        */
        
        //Method 2: using the simple pointor
        /*
        if (k <= 1 || head == nullptr || head->next == nullptr)
            return head;
        
        ListNode tmp;
        ListNode *tail = &tmp;
        ListNode *start = head;
        ListNode *end = head;
        
        int count = 1;
        while (end != nullptr)
        {
            if (count == k)
            {
                ListNode *theNext = end->next;
                reverseList(start, end);
                tail->next = end;
                tail = start;
                tail->next = theNext;
                start = end = theNext;
                count = 1;
            }
            else
            {
                end = end->next;
                count++;
            }
        }
        
        return tmp.next;
        */
        
        //Method 3: using the recursion method 
        if (k <= 1 || head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *end = head;
        
        int count = 1;
        while (end->next != nullptr && count < k)
        {
            end = end->next;
            ++count;
        }
        
        if (count == k)
        {
            ListNode *tail = end->next;
            reverseList(head, end);
            head->next = reverseKGroup(tail, k);
            return end;
        }
        else
        {
            return head;
        }
    }
};