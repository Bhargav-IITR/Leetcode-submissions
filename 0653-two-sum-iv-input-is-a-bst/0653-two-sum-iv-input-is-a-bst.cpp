/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    bool ans = false;
    void inorder(TreeNode* root, unordered_set <int> &m, int k){
        if(!root) return;
        inorder(root->left, m, k);
        //process curr
        if(m.count(k-root->val)){
            ans = true;
            return;
        }
        m.insert(root->val);
        inorder(root->right, m, k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set <int> m;
        inorder(root, m, k);
        return ans;
    }
};