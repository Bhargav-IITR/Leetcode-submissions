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
        if(!root) return NULL;
        int lnum = 0, rnum = 0;
        TreeNode* leftExist = func(root->left, k, &lnum);
        TreeNode* rightExist = func(root->right,k-1-lnum, &rnum);
        *num = lnum + rnum +1;
        if(lnum==k-1) return root;
        if(leftExist) return leftExist;
        if(rightExist) return rightExist;
        return NULL;
    }

    int kthSmallest(TreeNode* root, int k) {
        int *num = new int();
        TreeNode* ans = func(root,k,num);
        return (ans)?(ans->val):-1;
    }
};