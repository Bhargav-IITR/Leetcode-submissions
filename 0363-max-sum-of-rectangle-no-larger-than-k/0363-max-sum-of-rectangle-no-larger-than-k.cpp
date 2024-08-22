class Solution {
public:

    int getMaxSum(vector<int> &a, int k){
        int n = a.size(), ans = INT_MIN;
        a.insert(a.begin(), 0);
        for(int i = 1 ; i <= n ; i++) a[i] += a[i-1];
        set <int> st;
        st.insert(0);
        for(int j=1 ; j <= n ; j++){
            auto it = lower_bound(st.begin(), st.end(), a[j]-k);
            if(it != st.end()) ans = max(ans, a[j]-*it);
            st.insert(a[j]);
        }
        return ans;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector <int> a(n,0);
        matrix.insert(matrix.begin(), a);
        for(int i = 1 ; i <= m ; i++){
            for(int j = 0 ; j < n ; j++){
                matrix[i][j] += matrix[i-1][j];
            }
        } // construct te vertical prefix 2d array
        int ans = INT_MIN;
        for(int i = 1 ; i <= m ; i++){
            for(int j = i ; j <= m ; j++){
                vector <int> temp(n,0);
                for(int k = 0 ; k < n ; k++) temp[k] = matrix[j][k]-matrix[i-1][k]; //constructed the required array
                //apply kadane algorithm on it:
                int tmp = getMaxSum(temp, k);
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};