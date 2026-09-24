class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector <int> indegree(n, 0);
        vector <vector <int>> adj(n, vector <int> ());
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        queue <int> q;
        for(int node= 0 ; node <n ;node++) if(indegree[node] == 0) q.push(node);
        unordered_map <int, unordered_set<int>> pre;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int adjNode : adj[node]){
                pre[adjNode].insert(node);
                for(int preReq : pre[node]) pre[adjNode].insert(preReq);
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        vector <bool> ans;
        for(auto query : queries){
            int u = query[0], v = query[1];
            ans.push_back(pre[v].find(u) != pre[v].end());
        }
        return ans;
    }
};