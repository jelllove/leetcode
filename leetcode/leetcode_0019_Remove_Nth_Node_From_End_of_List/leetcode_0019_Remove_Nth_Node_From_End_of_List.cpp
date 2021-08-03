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

        //Method 1:
        /*
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
        */

        //Method 2: optimized method
        ListNode *prev = head; //保存原来的那个头指针
        ListNode *fast = head; //找到一个fast指针用来最后指向最后一个点
        
        //让FAST一直往前走N步
        while (n > 0 && fast != nullptr)
        {
            fast = fast->next;
            --n;
        }
        
        //然后FAST和HEAD一起走
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next;
            head = head->next;
        }
        
        //如果FAST最后是空的，那只有一种情况，就是要把HEAD给删除掉
        if (fast == nullptr)
        {
            prev = prev->next;
            
            return prev;
        }
        else
        {
            //如果不是的话，就把HEAD的下一个给去掉就可以了
            head->next = head->next->next;
            return prev;
        }
    }
};