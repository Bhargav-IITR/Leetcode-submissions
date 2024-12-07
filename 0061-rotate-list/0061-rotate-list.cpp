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
        if(!head || !head->next) return head;
        int l = 0;
        ListNode* temp= head;
        ListNode* last = temp;
        while(temp){
            last = temp;
            l++;
            temp = temp->next;
        }
        k = k%l;
        if(k == 0) return head;
        // first go to n-k th node;
        int cnt = 1;
        temp = head;
        while(cnt != l-k){
            temp = temp->next;
            cnt++;
        }
        //rn at n-k th node;
        ListNode* newhead = temp->next;
        temp->next = NULL;
        last->next = head;
        return newhead;
    }
};