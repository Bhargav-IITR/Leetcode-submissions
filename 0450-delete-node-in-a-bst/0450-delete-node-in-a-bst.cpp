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
    TreeNode* deleteHelp(TreeNode* node){
        if(!node->left) return node->right;
        if(!node->right) return node->left;
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        TreeNode* toReturn = left;
        while(left->right){
            left = left->right;
        }
        left->right = right;
        return toReturn;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key < root->val){
            root->left = deleteNode(root->left, key);
            return root;
        }else if(key > root->val){
            root->right = deleteNode(root->right, key);
            return root;
        }else{
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            TreeNode* right = root->right;
            TreeNode* left = root->left;
            TreeNode* toReturn = root->left;
            while(left->right) left = left->right;
            left->right = right;
            return toReturn;
        }
    }
};