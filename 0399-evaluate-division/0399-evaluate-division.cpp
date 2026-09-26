class Solution {
public:
    double dfs(string &num, string &den, unordered_map <string, unordered_map<string, double>> &adj, map <string, int> &vis){
        if(adj.find(num) == adj.end()) return -1;
        if(adj[num].find(den) != adj[num].end()) return adj[num][den];
        double ans = 1;
        for(auto &it : adj[num]){
            string dn = it.first;
            double val = it.second;
            if(vis[dn] == 1) continue;
            vis[dn] = 1;
            double tmp = dfs(dn, den, adj, vis);
            if(tmp != -1){
                return adj[num][den] = tmp*val;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map <string, unordered_map<string, double>> adj;
        for(int i = 0 ; i < equations.size(); i++){
            string num = equations[i][0], den = equations[i][1];
            double val = values[i];
            adj[num][num] = 1;
            adj[den][den] = 1;
            adj[num][den] = val;
            adj[den][num] = 1.0/val;
        }
        map<string, int> vis;
        vector<double>final;
        for(auto it : queries){
            string num = it[0], den = it[1];
            final.push_back(dfs(num, den, adj, vis));
            vis.clear();
        }
        return final;        
    }
};