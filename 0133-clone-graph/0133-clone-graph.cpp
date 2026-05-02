/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map <Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(mp[node]) return mp[node];
        Node* NODE = new Node(node->val);
        mp[node] = NODE;
        for(Node* n : node->neighbors){
            NODE->neighbors.push_back(cloneGraph(n));
        }
        return NODE;
    }
};