class DSU{
    vector <int> parent, rank, size;
    public:
        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            for(int i = 0 ;i < n+1; i++) parent[i] = i;;            
        }

        int findParent(int u){
            if(parent[u] == u) return u;
            int p = findParent(parent[u]);
            return parent[u] = p;
        }

        void unionByRank(int u, int v){
            int upu = findParent(u);
            int upv = findParent(v);
            if(upu == upv) return;
            if(rank[upu] > rank[upv]){
                parent[upv] = upu;
            }else if(rank[upu] < rank[upv]){
                parent[upu] = upv;
            }else{
                parent[upu] = upv;
                rank[upv]++;
            }
        }

        void unionBySize(int u, int v){
            int upu = findParent(u);
            int upv = findParent(v);
            if(upu == upv) return;
            if(size[upu] > size[upv]){
                parent[upv] = upu;
                size[upu] += size[upv];
            }else if(size[upv] >= size[upu]){
                parent[upu] = upv;
                size[upv] += size[upu];
            }
        }
};

class Solution {
public:
    // first idea - 
    // if one node indegree = 2 and other 1, remove one incoming edge from indegree 2 node 
    // if all indegree = 1, means there's a cycle. find that cycle and return the correct edge in cycle whic is invalid
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        set <int> st;
        for(auto edge : edges) {
            st.insert(edge[0]);
            st.insert(edge[1]);
        }
        int n = st.size();
        vector <int> indegree(n+1, 0);
        int nodeTwoInd = -1;
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            indegree[v]++;
            if(indegree[v] == 2) nodeTwoInd = v;
        }
        if(nodeTwoInd == -1){
            DSU dsu(n);
            for(auto edge : edges){
                int u = edge[0], v = edge[1];
                if(dsu.findParent(u) == dsu.findParent(v)){
                    return edge;
                }else{
                    dsu.unionByRank(u, v);
                }
            }
            return {};
        }else{
            // find the 2 incoming edges :
            vector <vector <int>> candidates;
            for(auto edge : edges){
                if(edge[1] == nodeTwoInd) candidates.push_back(edge);
            }
            vector <int> c1 = candidates[0];
            vector <int> c2 = candidates[1];
            // skip c1 - if still cycle then answer = c2, else answer = c1;
            DSU dsu(n);
            for(auto edge : edges){
                if(edge == c2) continue;
                int u = edge[0], v = edge[1];
                if(dsu.findParent(u) == dsu.findParent(v)){
                    return c1;
                }
                dsu.unionByRank(u, v);
            }
            return c2;
        }
        return {};
    }
};