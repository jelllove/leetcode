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
    
    ListNode* reverseLink(ListNode* link)
    {
        if (link == nullptr || link->next == nullptr)
            return link;
        
        ListNode *head = link;
        link = link->next;
        head->next = nullptr;
        
        while (link != nullptr)
        {
            ListNode *cur = link;
            link = link->next;
            cur->next = head;
            head = cur;
        }
        
        return head;
    }
    
    ListNode* addTwoLink(ListNode* l1, ListNode* l2, int pro)
    {
        if (l1 == nullptr && l2 == nullptr && pro == 0)
            return NULL;
        
        int num1 = (l1 == nullptr) ? 0 : l1->val;
        int num2 = (l2 == nullptr) ? 0 : l2->val;
        
        int n = num1 + num2 + pro;
        pro = n / 10;
        n %= 10;
        
        ListNode *node = new ListNode(n);
        
        node->next = addTwoLink((l1 == nullptr) ? nullptr : l1->next, 
                                (l2 == nullptr) ? nullptr : l2->next,
                                pro);
        
        return node;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Method 1: Reverse the links first, and add them, finally reverse again.
        ListNode* linkA = reverseLink(l1);
        ListNode* linkB = reverseLink(l2);
        
        ListNode* linkC = addTwoLink(linkA, linkB, 0);
        
        return reverseLink(linkC);
        
    }
};