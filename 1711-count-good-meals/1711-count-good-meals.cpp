#define ll long long
class Solution {
public:
    int countPairs(vector<int>& del) {
        vector <ll> list;
        for(int i = 0 ; i <=21 ; i++) {
            ll x = (1<<i);
            list.push_back(x);
        }
        sort(del.begin(), del.end());
        int n = del.size();
        ll mod = 1e9+7;
        ll ans = 0;
        map <int, int> delVsNum;
        for(int i = 0 ; i < n ; i++){
            ll num1 = (ll)del[i];
            for(int j = 0 ; (j <= 21) ; j++){
                ll num2 = list[j] - num1;
                ans = (ans + delVsNum[num2])%mod;
            }
            delVsNum[num1]++;
        }
        return (int)ans;
    }
};