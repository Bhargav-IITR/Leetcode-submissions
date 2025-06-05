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

    //--------noob solution ----------------//
    //map <int, int> p;
    // TreeNode* func(vector <int> &post, vector <int> &in){
        
    //     int n = post.size();
    //     if(n == 0) return NULL;
    //     TreeNode* root = new TreeNode(post[n-1]);
    //     int pos = 0;
    //     for(int i = 0 ; i < in.size(); i++){
    //         if(in[i] == post[n-1]){
    //             pos = i;
    //             break;
    //         }
    //     }

    //     vector <int> newPostLeft, newInLeft;
    //     int i = 1;
    //     for(i ; i <= pos ; i++){
    //         newPostLeft.push_back(post[i-1]);
    //     }
    //     for(int j = 0 ; j < pos ; j++) newInLeft.push_back(in[j]);
    //     root->left = func(newPostLeft, newInLeft);

    //     vector <int> newPostRight, newInRight;
    //     for(i ; i <= n-1 ; i++){
    //         newPostRight.push_back(post[i-1]);
    //     }
    //     for(int j = pos+1 ; j < n ; j++) newInRight.push_back(in[j]);

    //     root->right = func(newPostRight, newInRight);
    //     return root;
    // }
    // --------noob solution -------------//

    //---------pro-solution------------//
    map <int, int> a;
    TreeNode* func(vector <int> &post, vector <int> &in, int si, int ei, int sp, int ep){
        if(si > ei || sp > ep) return NULL;
        TreeNode* root = new TreeNode(post[ep]);
        int pos = a[post[ep]];

        int numleft = pos - si;

        root->left = func(post, in, si, pos-1, sp, sp+numleft-1);
        root->right = func(post, in, pos+1, ei, sp+numleft, ep-1);
        return root;
    }
    //---------pro-solution-----------//
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0 ; i < inorder.size() ; i++) a[inorder[i]] = i;
        return func(postorder, inorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};