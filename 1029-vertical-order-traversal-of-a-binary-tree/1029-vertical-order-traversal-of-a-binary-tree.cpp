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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map <int, map <int, multiset<int>>> mp;
        queue <pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* f = it.first;
            int col = it.second.first, lvl = it.second.second;
            mp[col][lvl].insert(f->val);
            if(f->left){
                q.push({f->left, {col-1,lvl+1}});
            }
            if(f->right){
                q.push({f->right, {col+1,lvl+1}});
            }
        }

        for(auto it: mp){
            vector<int> tmp;
            for(auto lvl:it.second){
                //lvl.second - > set
                for(auto v : lvl.second) tmp.push_back(v);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};