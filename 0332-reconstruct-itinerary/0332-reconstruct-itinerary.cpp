class Solution {
public:
    map<string, vector<string>> adj;
    vector<string> ans;

    void dfs(string node) {
        while (!adj[node].empty()) {
            string next = adj[node].front();
            adj[node].erase(adj[node].begin());
            dfs(next);
        }
        ans.push_back(node);  // post-order: add AFTER all edges are used
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        for (auto& t : tickets)
            adj[t[0]].push_back(t[1]);

        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};