class disjointSet{
public:
    vector <int> rank; vector  <int> parent;
    disjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        for(int i = 0 ; i <= n ; i++) parent[i]= i;
    }
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set <int> s;
        for(auto it : edges){
            s.insert(it[0]);
            s.insert(it[1]);
        }
        int n = s.size();
        disjointSet st(n);
        vector<int> ans;
        for(auto it : edges){
            int u = it[0], v = it[1];
            int ulp_u = st.findParent(u), ulp_v = st.findParent(v);
            if(ulp_u == ulp_v){
                ans = it;
            }
            else st.unionByRank(u,v);
        }
        return ans;
    }
};