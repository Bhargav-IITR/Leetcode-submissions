class Node{
    int key;
    int val;
    Node prev;
    Node next;
    Node(int key, int val){
        this.key = key;
        this.val = val;
    }
}

class LRUCache {

    int cap;
    Node head;
    Node tail;
    HashMap <Integer, Node> mp;

    public LRUCache(int capacity) {
        this.cap = capacity;
        mp = new HashMap<>();
        head = new Node(-1,-1);
        tail = new Node(-1, -1);
        head.next= tail;
        tail.prev = head;
    }
    
    public void deleteNode(Node node){
        Node pre = node.prev;
        Node nxt = node.next;
        pre.next = nxt;
        nxt.prev = pre;
    }

    public void insertAfterHead(Node node){
        Node tmp = head.next;
        head.next = node;
        node.prev = head;
        tmp.prev = node;
        node.next = tmp;
    }

    public int get(int key) {
        if(!mp.containsKey(key)){
            return -1;
        }
        Node node = mp.get(key);
        deleteNode(node);
        insertAfterHead(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        if(mp.containsKey(key)){
            Node node = mp.get(key);
            node.val = value;
            deleteNode(node);
            insertAfterHead(node);
        }else{
            if(mp.size() == cap){
                Node lru = tail.prev;
                deleteNode(lru);
                mp.remove(lru.key);
            }
            Node node = new Node(key, value);
            insertAfterHead(node);
            mp.put(key, node);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */