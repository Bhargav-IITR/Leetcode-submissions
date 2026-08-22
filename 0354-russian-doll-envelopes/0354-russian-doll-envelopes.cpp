class Solution {
public:

    int lis(vector <int> &a){
        int n = a.size();
        vector <int> ls;
        for(int i = 0 ; i < n ; i++){
            if((ls.size() == 0) || (ls[ls.size()-1] < a[i])) ls.push_back(a[i]);
            else{
                auto it = lower_bound(ls.begin(), ls.end(), a[i]);
                *it = a[i];
            }
        }
        return ls.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const vector <int> &a, const vector <int> &b){
            if(a[0] == b[0]) return b[1] < a[1];
            return a[0] < b[0];
        });
        vector <int> ht;
        for(auto it : envelopes) ht.push_back(it[1]);
        // apply LIS to height; O(nlog(n)) 
        return lis(ht);
    }   
};