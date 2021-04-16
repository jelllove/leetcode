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
    
    long long convertInt(ListNode *l)
    {
        long long  ans = 0;
        long long  pro = 1;
        while (l != nullptr)
        {
            ans += (l->val * pro);
            l = l->next;
            pro *= 10;
        }
        return ans;
    }
    
    ListNode* addTwoLink(ListNode* l1, ListNode* l2, int pro)
    {
        if (l1 == nullptr && l2 == nullptr && pro == 0)
            return nullptr;
        
        int num1 = (l1 != nullptr) ? l1->val : 0;
        int num2 = (l2 != nullptr) ? l2->val : 0;
        
        int n = num1 + num2 + pro;
        pro = n / 10;
        n %= 10;
        
        ListNode *node = new ListNode(n);
        node->next = addTwoLink(l1 == nullptr ? nullptr : l1->next, 
                                l2 == nullptr ? nullptr : l2->next, pro);
        
        return node;
        
        
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Method 1: 先得到那个link上的数，然后相加，再最后解开来
        //看上去是可行的，但是事实上是不可以的，因为如果它给的数是远超INT/LONG/LONG LONG的范围的呢
        /*
        long long  num1 = convertInt(l1);
        long long  num2 = convertInt(l2);
        
        long long  ans = num1 + num2;
        
        
        ListNode *head = new ListNode(ans % 10);
        head->next = NULL;
        ListNode *tail = head;
        ans /= 10;
        
        while (ans > 0)
        {
            ListNode *n = new ListNode(ans % 10);
            n->next = NULL;
            tail->next = n;
            tail = n;
            ans /= 10;
        }
        
        return head;
        */
        
        //Method 2:一个节点一个节点的去加起来
        /*
        int pro = 0;
        
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int num1 = 0;
        int num2 = 0;
        int n = 0;
        
        while (l1 != NULL || l2 != NULL || pro != 0)
        {
            if (l1 != NULL)
            {
                num1 = l1->val;
                l1 = l1->next;
            }
            else
            {
                num1 = 0;
            }
                
            
            if (l2 != NULL)
            {
                num2 = l2->val;
                l2 = l2->next;
            }
            else
            {
                num2 = 0;
            }
            
            n = num1 + num2 + pro;
            pro = n / 10;
            n %= 10;
            
            ListNode *node = new ListNode(n, nullptr);
            tail->next = node;
            tail  = node;
        }
        
        return head->next;
        */
        
        //Method 3: 使用递归Recursion
        return addTwoLink(l1, l2, 0);
        
    }
};