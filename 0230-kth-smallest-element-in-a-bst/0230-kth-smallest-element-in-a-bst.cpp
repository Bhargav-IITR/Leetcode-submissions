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
    TreeNode* func(TreeNode* root, int k, int *num){
        if(!root) return root;
        int left = 0, right = 0;
        TreeNode* l = func(root->left, k, &left);
        TreeNode* r = func(root->right, k-1-left, &right);
        *num = left+right+1;
        if(left == k-1) return root;
        if(l) return l;
        if(r) return r;
        return NULL;
    }
    int kthSmallest(TreeNode* root, int k) {
        int num = 0;
        TreeNode* ans = func(root, k, &num);
        return ans->val;
    }
};