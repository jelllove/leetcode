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
    
struct Compare
{
        bool operator () (ListNode* a, ListNode* b)
        {
            return a->val >= b->val;
        }
};

private:
    ListNode* getMid(ListNode* head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        ListNode *prev = nullptr;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = nullptr;
        
        return slow;
    }
    
    
    ListNode* merge(ListNode *left, ListNode *right)
    {
        ListNode tmp;
        ListNode *tail = &tmp;
        
        while (left != nullptr && right != nullptr)
        {
            if (left->val < right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else 
            {
                tail->next = right;
                right = right->next;
            }
            
            tail = tail->next;
            tail->next = nullptr;
        }
        
        if (left != nullptr)
            tail->next = left;
        else if (right != nullptr)
            tail->next = right;
        
        return tmp.next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        
        //Method 1: Using the min heap, but it is not efficiency
        /*
        priority_queue<ListNode*, vector<ListNode *>, Compare> que;
        
        while (head != nullptr)
        {
            que.push(head);
            head = head->next;
        }
        
        ListNode tmp;
        ListNode *tail = &tmp;
        
        while (!que.empty())
        {
            tail->next = que.top();
            que.pop();
            tail = tail->next;
            tail->next = nullptr;
        }
        
        return tmp.next;
        */
        
        //Method 2: merge sort
        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        return merge(left, right);
        
        
    }
};