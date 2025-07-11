class disjointSet{
    vector <int> rank, parent;
  public:
    disjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0 ; i <= n ; i++) parent[i] = i;
    }
    
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]); // path compression
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        int ru = rank[ulp_u], rv = rank[ulp_v];
        if(ru < rv){
            parent[ulp_u] = ulp_v;
        }else if(rv < ru){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjointSet dsu(n);
        unordered_map <string, int> stringNode;
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string s = accounts[i][j];
                if(stringNode.find(s) == stringNode.end()) stringNode[s] = i;
                else{
                    dsu.unionByRank(i, stringNode[s]);
                }
            }
        }
        vector <vector<string>> temp(n);
        for(auto it : stringNode){
            int ulNode = dsu.findParent(it.second);
            temp[ulNode].push_back(it.first);
        }
        vector <vector <string>> ans;
        for(int i = 0 ; i < temp.size() ; i++){
            if(temp[i].size() == 0) continue;
            vector <string> t = temp[i];
            sort(t.begin(), t.end());
            t.insert(t.begin(), accounts[i][0]);
            ans.push_back(t);
        }
        return ans;
    }
};