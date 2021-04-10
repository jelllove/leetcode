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
    
    
    ListNode* helper(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL)
            return l2;
        
        if (l2 == NULL)
            return l1;
        
        if (l1->val < l2->val)
        {
            //最精华的是这一段，如果发现L1的比L2的要小的就用这个结节继续递归
            l1->next = helper(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = helper(l1, l2->next);
            return l2;
        }
    }
    
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL && l2 == NULL)
            return NULL;
        
        //Method 1: 常规做法，利用一个while，然后一个个比较两个link的头的大小
        /*
        ListNode *head = NULL;  //返回的头
        ListNode *tail = NULL; //尾部指针
        ListNode *tmp = NULL; //临时的指针
        
        while (l1 != NULL || l2 != NULL)
        {
            //如果有一个指针已经空了，那这个循环就结束了
            if (l1 == NULL)
            {
                if (tail == NULL)
                {
                    head = l2;
                }
                else
                {
                    tail->next = l2;
                }
                
                break;
                    
            }
            else if (l2 == NULL)
            {
                if (tail == NULL)
                {
                    head = l1;
                }
                else
                {
                    tail->next = l1;
                }
                break;
            }
            else
            {
                //如果两个指针都还没有到尽头的话，那就继续比较，找出小的那个接上去
                if (l1->val < l2->val)
                {
                    tmp = l1;
                    l1 = l1->next;
                }
                else
                {
                    tmp = l2;
                    l2 = l2->next;
                }
                
                tmp->next = NULL;
                
                if (head == NULL)
                {
                    head = tmp;
                    tail = tmp;
                }
                else
                {
                    tail->next = tmp;
                    tail = tmp;
                }
            }
        }
        
        return head;
        */
        
        //Method 2: 利用递归，然后利用现在的list，把一个合并到另一个中
        return helper(l1, l2);
        
    }
};