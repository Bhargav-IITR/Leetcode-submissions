class Solution {
public:
    int findPeakRow(vector <int> &row){
        int i = 0, maxi = INT_MIN;
        for(int j = 0 ; j < row.size() ; j++){
            if(row[j] > maxi){
                maxi = row[j];
                i = j;
            }
        }
        return i;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int lo = 0, hi = mat.size()-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int i = findPeakRow(mat[mid]);
            int top = (mid == 0) ? -1 : mat[mid-1][i];
            int down = (mid == mat.size()-1) ? -1 : mat[mid+1][i];
            if((top < mat[mid][i]) && (mat[mid][i] > down)) return {mid, i};
            else if((top > mat[mid][i]) && (mat[mid][i] > down)) hi = mid-1;
            else if((top < mat[mid][i]) && (mat[mid][i] < down)) lo = mid+1;
            else lo = mid+1;
        }
        return {};
    }
};