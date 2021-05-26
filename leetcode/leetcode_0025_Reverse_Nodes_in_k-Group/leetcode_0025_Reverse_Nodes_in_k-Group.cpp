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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;
        
        //Method 1: go thorugh and store in the vector
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
    }
};