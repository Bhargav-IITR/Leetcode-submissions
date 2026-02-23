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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> inorder;
        TreeNode* cur = root;
        while(cur){
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }else{
                TreeNode* right = cur->left;
                while(right->right && right->right != cur){
                    right = right->right;
                }
                if(right->right == NULL){
                    right->right = cur;
                    cur = cur->left;
                }else{
                    right->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
}; 