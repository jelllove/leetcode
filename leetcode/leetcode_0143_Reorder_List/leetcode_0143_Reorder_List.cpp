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

ListNode* rev(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* nxt;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

void reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return;
    }
    ListNode* slow = head; 
    ListNode* fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* endhead = rev(slow);
    ListNode* starthead = head;
    while(endhead != NULL){
        ListNode* ehead = endhead->next;
        ListNode* shead = starthead->next;
        starthead->next = endhead;
        endhead->next = shead;
        endhead = ehead;
        starthead = shead;
    }
    if(starthead != NULL){
        starthead->next = NULL;
    }
}
};