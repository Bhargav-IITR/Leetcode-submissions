class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector <int> diff(n);
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            diff[i] = arr[i]-(i+1);
            if(diff[i] >= k){
                return i + k;
            }
        }
        return n + k;
    }
};