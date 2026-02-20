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
        int temp = max(root->val, max(left+root->val, max(right+root->val, left+right+root->val)));
        ans = max(ans, temp);
        return max(root->val, max(left+root->val, right+root->val));
    }
    int maxPathSum(TreeNode* root) {
        func(root);
        return ans;
    }
};