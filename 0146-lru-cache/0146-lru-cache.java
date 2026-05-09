import java.util.HashMap;
import java.util.concurrent.locks.ReentrantLock;

class Node {

    int key;
    int val;

    Node prev;
    Node next;

    Node(int key, int val) {
        this.key = key;
        this.val = val;
    }
}

class LRUCache {

    private final int cap;

    private final HashMap<Integer, Node> mp;

    private final Node head;
    private final Node tail;

    // explicit lock
    private final ReentrantLock lock = new ReentrantLock();

    public LRUCache(int capacity) {

        this.cap = capacity;

        mp = new HashMap<>();

        // dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head.next = tail;
        tail.prev = head;
    }

    // remove node from DLL
    private void deleteNode(Node node) {

        Node pre = node.prev;
        Node nxt = node.next;

        pre.next = nxt;
        nxt.prev = pre;
    }

    // insert right after head
    private void insertAfterHead(Node node) {

        Node temp = head.next;

        head.next = node;
        node.prev = head;

        node.next = temp;
        temp.prev = node;
    }

    public int get(int key) {

        lock.lock();

        try {

            if(!mp.containsKey(key)) {
                return -1;
            }

            Node node = mp.get(key);

            // move to front
            deleteNode(node);
            insertAfterHead(node);

            return node.val;

        } finally {

            // ALWAYS unlock
            lock.unlock();
        }
    }

    public void put(int key, int value) {

        lock.lock();

        try {

            // key already exists
            if(mp.containsKey(key)) {

                Node node = mp.get(key);

                node.val = value;

                deleteNode(node);
                insertAfterHead(node);

            } else {

                // cache full
                if(mp.size() == cap) {

                    Node lru = tail.prev;

                    deleteNode(lru);

                    mp.remove(lru.key);
                }

                Node newNode = new Node(key, value);

                insertAfterHead(newNode);

                mp.put(key, newNode);
            }

        } finally {

            // ALWAYS unlock
            lock.unlock();
        }
    }
}