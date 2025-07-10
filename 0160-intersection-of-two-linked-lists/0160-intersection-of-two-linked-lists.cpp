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
    // int len(ListNode* head){
    //     int cnt = 0;
    //     while(head){
    //         cnt++;
    //         head = head->next;
    //     }
    //     return cnt;
    // }
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     if(!headA || !headB) return NULL;
    //     int l1 = len(headA);
    //     int l2 = len(headB);
    //     if(l2 < l1) return getIntersectionNode(headB, headA);
    //     int dif = l2-l1;
    //     ListNode* t = headB;
    //     while(dif){
    //         t = t->next;
    //         dif--;
    //     }
    //     ListNode* s = headA;
    //     while(t && s && t != s){
    //         t = t->next;
    //         s = s->next;
    //     }
    //     return t;
    // }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        if(headA == headB) return headA;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2){
            if(t1 == NULL) t1 = headB;
            else t1 = t1->next;
            if(t2 == NULL) t2 = headA;
            else t2 = t2->next;
        }
        return t1;
    }
};