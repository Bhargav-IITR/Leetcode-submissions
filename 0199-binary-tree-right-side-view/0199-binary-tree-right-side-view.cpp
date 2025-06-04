/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(NULLptr), right(NULLptr) {}
 *     TreeNode(int x) : val(x), left(NULLptr), right(NULLptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector <int> ans;
    void bfs(TreeNode* root){
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr != NULL){
                if(q.front() == NULL){
                    ans.push_back(curr->val);
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(q.front() == NULL) q.push(NULL);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return ans;
        bfs(root);
        return ans;
    }
};