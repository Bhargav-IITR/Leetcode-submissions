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
    int ans = INT_MIN;
    int func(TreeNode* root){
        if(!root) return 0;
        int left = func(root->left);
        int right = func(root->right);
        ans = max(ans, max(root->val, max(left+right+root->val, max(left+root->val, right+root->val))));
        return root->val + max(0, max(left, right));
    }
    int maxPathSum(TreeNode* root) {
        func(root);
        return ans;
    }
};