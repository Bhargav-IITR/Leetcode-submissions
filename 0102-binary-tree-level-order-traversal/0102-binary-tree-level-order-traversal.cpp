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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector <vector <int>> ans;
        if(root == NULL)return ans;
        queue <TreeNode*> q, t1;
        q.push(root);
        vector <int> temp;
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            temp.push_back(f->val);
            if(f->left) t1.push(f->left);
            if(f->right) t1.push(f->right);
            if(q.empty()){
                while(!t1.empty()) q.push(t1.front()), t1.pop();
                ans.push_back(temp);
                temp.clear();
            }            
        }
        return ans;
    }
};