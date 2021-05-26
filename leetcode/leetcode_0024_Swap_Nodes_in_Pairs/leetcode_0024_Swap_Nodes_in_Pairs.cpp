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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        //Method 1: go through, and store in the vector;
    
        vector<ListNode *> vec;
        while (head != nullptr)
        {
            vec.push_back(head);
            head = head->next;
        }
        
        ListNode ans;
        ListNode *tail = &ans;
        
        for (int i = 0; i < vec.size(); i += 2)
        {
            if ((i + 1) < vec.size())
            {
                tail->next = vec[i + 1];
                tail = tail->next;
            }
            
            
            tail->next = vec[i];
            tail = tail->next;
            tail->next = nullptr;
        }
        
        return ans.next;
    }
};