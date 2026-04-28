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
    void serialise(TreeNode* root, string &s){
        if(!root){
            s += "#,";
            return;
        }
        s += "$" + to_string(root->val) + ",";
        serialise(root->left, s);
        serialise(root->right, s);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s,t;
        serialise(root, s);
        serialise(subRoot, t);
        return s.find(t) != string::npos;
    }
};