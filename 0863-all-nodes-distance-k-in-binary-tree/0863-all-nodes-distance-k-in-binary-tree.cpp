/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParent(TreeNode* root, map <TreeNode*, TreeNode*> &parent){
        if(!root) return;
        if(root->left){
            parent[root->left] = root;
            makeParent(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            makeParent(root->right, parent);
        }
    }
    void func(TreeNode* node, map <TreeNode*, TreeNode*> &parent, int k, vector <int> &ans, map <TreeNode*, int> &vis){
        if(!node) return;
        if(vis[node] == 1) return;
        if(k == 0){
            ans.push_back(node->val);
            return;
        }
        vis[node] = 1;
        func(node->left, parent, k-1, ans, vis);
        func(node->right, parent, k-1, ans, vis);
        if(parent[node] != node) func(parent[node], parent, k-1, ans, vis);
        // vis[node] = 0;
    }   
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        map <TreeNode*, TreeNode*> parent;
        map <TreeNode*, int> vis;
        makeParent(root, parent);
        parent[root] = root;
        vector <int> ans;
        func(target, parent, k, ans, vis);
        return ans;
    }
}; 