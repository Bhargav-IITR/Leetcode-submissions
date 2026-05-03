class Solution {
public: 
    int func(vector<int> &st) {
        vector<int> t(10, 0);

        for(auto it : st)
            t[it - 1] = 1;

        bool sec1 = (!t[1] && !t[2] && !t[3] && !t[4]); // 2-5
        bool sec2 = (!t[3] && !t[4] && !t[5] && !t[6]); // 4-7
        bool sec3 = (!t[5] && !t[6] && !t[7] && !t[8]); // 6-9

        if(sec1 && sec3) return 2;

        if(sec1 || sec2 || sec3) return 1;

        return 0;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        sort(rs.begin(), rs.end());
        map <int, vector<int>> mp;
        for(auto it : rs){
            int r = it[0], st = it[1];
            mp[r].push_back(st);
        }
        int ans = 0;
        for(auto it : mp){
            ans += func(it.second);
        }
        ans += 2*(n-mp.size());
        return ans;
    }
};