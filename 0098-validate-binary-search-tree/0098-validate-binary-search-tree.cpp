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
    long long mi = -1e10, ma = 1e10;
    bool validBST(TreeNode* root, long long min , long long max){
        if(root == NULL) return true;
        if(root->val >= max) return false;
        if(root->val <= min) return false;
        bool cnd1 = validBST(root->left, min, root->val);
        bool cnd2 = validBST(root->right, root->val, max);
        return cnd1 && cnd2;
    }
    bool isValidBST(TreeNode* root) {
        bool ans = validBST(root, mi, ma);
        return ans;        
    }
};