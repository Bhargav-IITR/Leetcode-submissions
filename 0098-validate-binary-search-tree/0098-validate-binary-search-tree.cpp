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
    long long int mi = -1e10, ma = 1e10;
    bool func(TreeNode* root, long long int mini, long long int maxi){
        if(!root) return true;
        if(root->val <= mini) return false;
        if(root->val >= maxi) return false;
        bool c1 = func(root->left, mini, root->val);
        bool c2 = func(root->right, root->val, maxi);
        return c1&&c2;
    }
    bool isValidBST(TreeNode* root) {
        return func(root, mi, ma);
    }
};