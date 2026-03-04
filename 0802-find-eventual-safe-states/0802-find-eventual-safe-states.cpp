class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <vector <int>> adj(n, vector <int> ());
        vector <int> indegree(n, 0);
        for(int u = 0 ; u < n ; u++){
            for(int v : graph[u]){
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        queue <int> q;
        for(int i = 0 ; i< n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector <int> tops;
        while(!q.empty()){
            int node = q.front();
            tops.push_back(node);
            q.pop();
            for(int adjNode : adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        sort(tops.begin(), tops.end());
        return tops;        
    }
};