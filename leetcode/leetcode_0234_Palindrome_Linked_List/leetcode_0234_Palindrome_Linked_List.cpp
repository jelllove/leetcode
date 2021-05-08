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
    bool isPalindrome(ListNode* head) {
        //Method 1: record the link into vector
        /*
        vector<int> vec;
        
        while (head != nullptr)
        {
            vec.push_back(head->val);
            head = head->next;
        }
        
        if (vec.size() == 0)
            return false;
        if (vec.size() == 1)
            return true;
        
        int i = 0, j = vec.size() - 1;
        
        while (i < j)
        {
            if (vec[i] != vec[j])
                return false;
            
            ++i;
            --j;
        }
        
        return true;
        */
        
        //Method 2: record the link into vector， but optimized
        /*
        if (head == nullptr)
            return false;
        if (head->next == nullptr)
            return true;
            
        vector<int> vec;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        vec.push_back(slow->val);
        
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            vec.push_back(slow->val);
        }
        slow = slow->next;
        
        if (fast->next != nullptr)
        {
            slow = slow->next;
        }
        int i = vec.size() - 1;
        while (slow != nullptr)
        {
            if (slow->val != vec[i])
                return false;
            slow = slow->next;
            --i;
        }
        
        return true;
        */
        
        //Method 3: reserve the link, but I do not think it is good.
        
        if (head == nullptr)
            return false;
        if (head->next == nullptr)
            return true;
        
        ListNode *cur = NULL;
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            
        }
        slow = slow->next;
        
        if (fast->next != nullptr)
        {
            slow = slow->next;
        }
        
        while (slow != nullptr)
        {
            ListNode *tmp = slow;
            slow = slow->next;
            tmp->next = cur;
            cur = tmp;
        }
        
        while (cur != nullptr)
        {
            if (cur->val != head->val)
                return false;
            
            cur = cur->next;
            head = head->next;
        }
        
        
        return true;
        
    }
};