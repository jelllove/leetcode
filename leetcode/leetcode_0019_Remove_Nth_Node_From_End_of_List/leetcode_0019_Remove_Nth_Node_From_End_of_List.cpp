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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tail = head;
        
        //先用一个tail 指针往后移N步
        while (n > 0 && tail != NULL)
        {
            tail = tail->next;
            --n;
        }
        

        //如果发现tail已经到尾部了，说明要删除的是头指针
        if (tail == NULL)
        {
            head = head->next;
            return head;
        }
        
        
        //使用另一个指针，跟着tail指针一起往后移，一直到tail 到达达尾部
        ListNode *front = head;
        while (true)
        {
            tail = tail->next;
            
            if (tail == NULL)
            {
                //当tail到达尾部下，front指针的下一个目标就是要删除的对象了
                front->next = front->next->next;
                break;
            }
            else
            {
                //如果tail还没有到达尾部，那front也走一步
                front = front->next;
            }
        }
        
        return head;
    }
};