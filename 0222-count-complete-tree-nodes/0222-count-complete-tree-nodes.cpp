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
    int getHeight(TreeNode* root){
        int cnt = 0;
        if(!root) return 0;
        while(root){
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if(lh == rh){
            return (1 << (lh)) +  countNodes(root->right);
        }else{
            return (1 << (rh)) + countNodes(root->left);
        }
    }
};