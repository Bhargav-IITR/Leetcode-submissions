class Node{
public:
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;
    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->freq = 1;
        prev = nullptr;
        next = nullptr;
    }
};
class DLL {
public:
    Node* head;
    Node* tail;
    int size;

    DLL(){
        head = new Node (-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void insertAfterHead(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }
    void deleteNode(Node* node){
        Node* pre = node->prev;
        Node* nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
        size--;
    }
};

class LFUCache {
public:
    int cap;
    // key -> node
    map <int, Node*> mp;

    // frequ -> DLL
    map <int, DLL> freqMp;
    int minFreq;


    LFUCache(int capacity) {
        this->cap = capacity;    
        minFreq = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        int fq = node->freq;
        node->freq++;
        freqMp[fq].deleteNode(node);
        if((fq == minFreq) && (freqMp[fq].size == 0)) minFreq++;
        freqMp[fq+1].insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        // key already exist : 
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            int fq= node->freq;
            node->freq++;
            node->val = value;
            freqMp[fq].deleteNode(node);
            if((fq == minFreq) && (freqMp[fq].size == 0)) minFreq++;
            freqMp[fq+1].insertAfterHead(node);
            return;
        }
        if(mp.size() == cap){
            Node* lastNode = freqMp[minFreq].tail->prev;
            mp.erase(lastNode->key);
            freqMp[minFreq].deleteNode(lastNode);
            if(freqMp[minFreq].size == 0) minFreq++;
        }
        //insert new node: 
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        freqMp[1].insertAfterHead(newNode);
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */