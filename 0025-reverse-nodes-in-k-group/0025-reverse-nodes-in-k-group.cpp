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
    bool kleft(ListNode* head, int k){
        ListNode* curr = head;
        int count = 0;
        while(curr != NULL && count < k){
            curr = curr->next;
            count++;
        }
        return (count == k);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        if(!kleft(head, k)) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tail = curr;
        ListNode* newHead;
        int count = 0;
        while((curr != NULL) && count < k){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        newHead = prev;
        tail->next = reverseKGroup(curr, k);
        return newHead;

    }
};