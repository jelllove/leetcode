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
    ListNode* rotateRight(ListNode* head, int k) {
        
        //Method 1: using the several pointer
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        
        //找出一共有几个结点
        int n = 1;
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            ++n;
            tail = tail->next;
        }
        
        //如果轮过来的次数正好是N的X倍，那就直接返回
        if (k % n == 0)
            return head;
        
        
        //找出应该在原来的链上的第几个点开始切割
        int left = n - (k % n);
        
        //根据这个找出那个要切割的点
        ListNode *prev = head;
        while (left > 1)
        {
            prev = prev->next;
            --left;
        }
        
        //在那个点切割掉
        tail->next = head;
        head = prev->next;
        prev->next = nullptr;
        
        return head;
        
        
        
    }
};