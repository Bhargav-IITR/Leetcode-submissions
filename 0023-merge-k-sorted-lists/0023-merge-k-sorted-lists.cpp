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
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeLists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <ListNode*> tmp;
        int n = lists.size();
        if(n == 0) return NULL;
        if(n == 1) return lists[0];
        while(n > 1){
            int k = (n+1)>>1;
            for(int i= 0 ; i < n/2; i++){
                lists[i] = mergeLists(lists[i], lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }
};