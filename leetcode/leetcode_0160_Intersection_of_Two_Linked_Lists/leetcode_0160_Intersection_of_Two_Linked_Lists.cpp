/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Method 1: hash remark, higher memory
        //利用hash表词表一条LINK上的所有指针，然后另一条走的时候，去看一下原来的hash就可以了
        /*set<ListNode *> setA;
        if (headA == NULL || headB == NULL)
            return NULL;
        
        while (headA != NULL)
        {
            setA.insert(headA);
            headA = headA->next;
        }
        
        while (headB != NULL)
        {
            if (setA.count(headB) >= 1)
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
        */


       //Method 2: Reduce the length
        /*
        //计算出两个link的长度，然后从头开始，让长的那一条多走几步，让他们一样长
        //这样就一步步看，只要走到一起了就相等了
        if (headA == NULL || headB == NULL)
            return NULL;
        
        int lenA = 0;
        int lenB = 0;
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        while (pA != NULL)
        {
            pA = pA->next;
            ++lenA;
        }
        
        while (pB != NULL)
        {
            pB = pB->next;
            ++lenB;
        }
        
        pA = headA;
        pB = headB;
        
        if (lenA > lenB)
        {
            while (lenA > lenB)
            {
                pA = pA->next;
                --lenA;
            }
        }
        else if (lenB > lenA)
        {
            while (lenB > lenA)
            {
                pB = pB->next;
                --lenB;
            }
        }
        
        
        while (pA != NULL && pB != NULL)
        {
            if (pA == pB)
                return pA;
            
            pA = pA->next;
            pB = pB->next;
        }
        
        return NULL;
        */
        
        //Method 3: two pointer, better solution
        if (headA == NULL || headB == NULL)
            return NULL;
        
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        while (pA != pB)
        {
            pA = pA->next;
            pB = pB->next;
            
            if (pA == pB)
                return pA;
            
            //当A或B走到了尽头之后，就从另一个的head那边开始走，
            //这样最后他们走的总的路是一样的，所以一定能遇上
            //而遇上的那个点就是交叉的那个地方，这个其实和那个一个环形链表上找第一个交叉点是一样的
            if (pA == NULL)
                pA = headB;
            
            if (pB == NULL)
                pB = headA;
        }
        
        return pA;
        
            
    }
};