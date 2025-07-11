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
    ListNode* sortList(ListNode* head) {
        if(!head || (!head->next)) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nextpart = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(nextpart);
        ListNode* final = merge(left, right);
        return final;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* newhead = new ListNode;
        ListNode* temp = newhead;
        while(left && right){
            if(left->val <= right->val){
                temp->next = left;
                temp = temp->next;
                left = left->next;
            }else{
                temp->next= right;
                temp = temp->next;
                right = right->next;
            }
        }
        temp->next = ((left)?left:right);
        return newhead->next;
    }

};