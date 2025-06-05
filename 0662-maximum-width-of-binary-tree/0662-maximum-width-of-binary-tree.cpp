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
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair <TreeNode* , long long int>> q;
        if(!root) return 0;
        long long int a = 1;
        q.push({root, a});
        int ans = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            int start = 0, end = 0;
            long long int level_min = q.front().second;
            for(int i = 0 ; i < size ; i++){
                auto tmp = q.front();
                q.pop();
                long long int pos = tmp.second - level_min;
                if(i == 0) start = pos;
                if(i == size-1) end = pos;

                if(tmp.first->left){
                    q.push({tmp.first->left, 2*pos + 1});
                }
                if(tmp.first->right){
                    q.push({tmp.first->right, 2*pos + 2});
                }                
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};