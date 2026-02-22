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
    // ps - preorder start ..... 
    TreeNode* tree(vector<int> &pre, vector<int> &in, int ps, int pe, int is, int ie, map<int,int> &mp){
    if(ps > pe) return NULL;

    TreeNode* node = new TreeNode(pre[ps]);

    int ind = mp[pre[ps]];
    int numLeft = ind - is;

    node->left = tree(pre, in, ps+1, ps+numLeft, is, ind-1, mp);
    node->right = tree(pre, in, ps+numLeft+1, pe, ind+1, ie, mp);

    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> mp;
    int n = preorder.size();

    for(int i = 0 ; i < n ; i++){
        mp[inorder[i]] = i;   // FIXED
    }

    return tree(preorder, inorder, 0, n-1, 0, n-1, mp);
}
};