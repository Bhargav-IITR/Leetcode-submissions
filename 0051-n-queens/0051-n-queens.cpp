class Solution {
public:
    vector <vector <string>> ans;
    void func(int col, int n, vector <string> &t, map<int,int>&l, map<int,int>&tl, map<int,int>&bl){
        if(col == n){
            ans.push_back(t);
            return;
        }
        for(int row = 0 ; row < n ; row++){
            bool left = (l[row] == 1)?true:false; //check left
            bool topLeft = (tl[row-col] == 1)?true:false; //check top left
            bool bottomLeft = (bl[row+col] == 1)?true:false; //check bottom left
            if(!left && !topLeft && !bottomLeft){
                l[row] = 1, tl[row-col] = 1, bl[row+col] = 1;
                t[row][col] = 'Q';
                func(col+1, n, t, l, tl, bl);
                //now backtrack
                t[row][col] = '.';
                l[row] = 0, tl[row-col] = 0, bl[row+col] = 0;                
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        vector <string> t(n);
        for(int i=0;i<n;i++) s += ".";
        for(int i=0;i<n;i++) t[i] = s;
        map<int,int> l, tl, bl;
        func(0,n,t,l,tl,bl);
        return ans;
    }
};