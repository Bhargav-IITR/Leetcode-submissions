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
    bool balanced(TreeNode* root, int *height){
        if(!root) return true;
        int lh = 0, rh = 0;
        bool leftB = balanced(root->left, &lh);
        bool rightB = balanced(root->right, &rh);
        *height = max(lh, rh) + 1;
        if(!leftB || !rightB) return false;
        if(abs(lh-rh) > 1) return false;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return balanced(root, &height);
    }
};