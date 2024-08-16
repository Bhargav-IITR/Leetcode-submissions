#define ll long long
class Solution {
public:
    const int mod = 1e9+7;
    vector <int> LS(vector <int> &a){
        int n = a.size();
        vector <int> ans(n);
        stack <int> st;
        for(int i= 0 ; i < n ; i++){
            while(!st.empty() && a[st.top()] >= a[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            else ans[i] = -1;
            st.push(i);
        }
        return ans;
    }
    vector <int> RS(vector <int> &a){
        int n = a.size();
        vector <int> ans(n);
        stack <int> st;
        for(int i= n-1 ; i >= 0 ; i--){
            while(!st.empty() && a[st.top()] > a[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            else ans[i] = n;
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector <int> leftSmall = LS(arr);
        vector <int> rightSmall = RS(arr);
        ll ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int lsInd = leftSmall[i], rsInd = rightSmall[i];
            int leftSubarrays = i-lsInd;
            int rightSubarrays = rsInd-i;
            ll ways = (1ll*leftSubarrays*rightSubarrays*arr[i])%mod;
            ans = (ans + ways)%mod;
        }
        return (int)ans;
    }
};