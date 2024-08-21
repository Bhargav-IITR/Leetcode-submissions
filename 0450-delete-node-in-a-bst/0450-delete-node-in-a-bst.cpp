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
    TreeNode* helper(TreeNode* node){ // node - nnode to delete
        if(!node->left) return node->right;
        if(!node->right) return node->left;
        TreeNode* r = node->right;
        TreeNode* l = node->left;
        TreeNode* newRoot = node->left;
        while(l->right){
            l = l->right;
        }
        l->right = r;
        delete(node);
        return newRoot;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) return helper(root);
        TreeNode* temp = root;
        while(temp){
            if(temp->val < key){
                if(temp->right && temp->right->val == key){
                    temp->right = helper(temp->right);
                    break;
                }else temp = temp->right;
            }
            else{
                if(temp->left && temp->left->val == key){
                    temp->left = helper(temp->left);
                    break;
                }else temp = temp->left;
            }
        }
        return root;
    }
};