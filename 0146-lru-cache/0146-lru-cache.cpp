class LRUCache {
public:
    struct ListNode {
        int key, val;
        ListNode* prev;
        ListNode* next;

        ListNode(int key, int value) : key(key), val(value), prev(NULL), next(NULL) {}
    };

    ListNode* head = new ListNode(0, 0);
    ListNode* tail = new ListNode(0, 0);
    int curr_cap = 0;
    int max_cap;
    map <int, ListNode*> hashmap;
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        max_cap = capacity;
    }

    int get(int key) {
        if (hashmap.find(key) == hashmap.end()) return -1;
        else {
            int ans = hashmap[key]->val;
            if (head->next != hashmap[key]) {
                ListNode* headnext = head->next;
                ListNode* curr = hashmap[key];
                ListNode* toinsert = new ListNode(curr->key, curr->val);
                ListNode* currprev = curr->prev;
                ListNode* currnext = curr->next;
                delete(curr);
                currprev->next = currnext;
                currnext->prev = currprev;
                head->next = toinsert;
                toinsert->prev = head;
                toinsert->next = headnext;
                headnext->prev = toinsert;
                hashmap[key] = toinsert;
            }
            return ans;
        }
    }

    void put(int key, int value) {
        if (curr_cap == max_cap && hashmap.find(key) == hashmap.end()) {
            ListNode* tailprev = tail->prev;
            ListNode* pre = tailprev->prev;
            pre->next = tail;
            tail->prev = pre;
            hashmap.erase(tailprev->key);
            delete(tailprev);
            curr_cap--;
        }
        if (hashmap.find(key) == hashmap.end()) curr_cap++;
        else {
            ListNode* curr = hashmap[key];
            hashmap.erase(key);
            ListNode* pre = curr->prev;
            ListNode* nxt = curr->next;
            delete(curr);
            pre->next = nxt;
            nxt->prev = pre;
        }
        ListNode* toinsert = new ListNode(key, value);
        ListNode* headnext = head->next;
        head->next = toinsert;
        toinsert->prev = head;
        toinsert->next = headnext;
        headnext->prev = toinsert;
        hashmap[key] = toinsert;

    }
};