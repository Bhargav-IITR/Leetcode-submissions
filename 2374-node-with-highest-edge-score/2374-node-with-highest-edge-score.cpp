class Solution {
#define ll long long
public:
    int edgeScore(vector<int>& edges) {
        map <int, ll > mp; // node -> label sum
        for(int i = 0 ; i < edges.size() ; i++){
            mp[edges[i]] += (ll)i;
        }
        ll maxScore = LLONG_MIN;
        int node = INT_MAX;
        for(auto it : mp){
            if(it.second >= maxScore){
                maxScore = it.second;
            }
        }
        for(auto it : mp) if(it.second == maxScore) node = min(node, it.first);
        return node;
    }
};