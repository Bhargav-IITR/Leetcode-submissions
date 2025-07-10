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
    ListNode* reverseList(ListNode* head) {
        // if(!head || (!head->next)) return head;
        // ListNode* pre = NULL;
        // ListNode* temp = head;
        // while(temp && temp->next){
        //     ListNode* n = temp->next;
        //     temp->next = pre;
        //     pre = temp;
        //     temp = n;
        // }
        // temp->next = pre;
        // return temp;
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* nextPart = reverseList(head->next);
        head->next = NULL;
        ListNode* t = nextPart;
        while(t->next){
            t = t->next;
        }
        t->next = head;
        return nextPart;
    }
};