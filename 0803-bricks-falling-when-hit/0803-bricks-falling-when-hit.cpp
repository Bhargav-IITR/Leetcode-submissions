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
        int getSize(int node){
            return size[findParent(node)];
        }
};

int nodeNum(int n, int m, int row, int col){
    return row * m + col;
}

pair<int, int> resolveNode(int n, int m, int node){
    return {node / m, node % m};
}

bool valid(int n, int m, int i, int j, vector <vector<int>> &grid){
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1;
}

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = grid.size(), m = grid[0].size();
        int totalNode = n*m;
        DSU dsu(totalNode+1);
        set <int> hit;
        vector <vector <int>> g(grid);
        int hs = hits.size();
        for(auto it : hits){
            int node = nodeNum(n, m, it[0], it[1]);
            hit.insert(node);
            g[it[0]][it[1]] = 0;
        }
        int maxNode = n*m;
        vector <int> dir = {-1,0,1,0,-1};
        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(g[i][j] == 0) continue;
                int node = nodeNum(n,m,i,j);
                if(hit.count(node) > 0) continue;
                if(i == 0) dsu.unionBySize(node, maxNode);
                for(int k = 0 ; k < 4 ; k++){
                    int ni = i + dir[k];
                    int nj = j + dir[k+1];
                    if(valid(n,m, ni,nj,g)) {
                        dsu.unionBySize(node, nodeNum(n,m,ni,nj));
                    }
                }
            }
        }
        vector <int> ans;
        for(int i = hs-1 ; i >= 0 ; i--){
            if(grid[hits[i][0]][hits[i][1]] == 0){
                ans.push_back(0);
                continue;
            }
            g[hits[i][0]][hits[i][1]] = 1;
            int ceilSize = dsu.getSize(maxNode);
            int hitNode = nodeNum(n, m, hits[i][0], hits[i][1]);
            if(hits[i][0] == 0) dsu.unionBySize(hitNode, maxNode);
            for(int k = 0 ; k < 4 ; k++){
                int ni = hits[i][0] + dir[k];
                int nj = hits[i][1] + dir[k+1];
                if(valid(n,m, ni,nj,g)) {
                    dsu.unionBySize(hitNode, nodeNum(n,m,ni,nj));
                }
            }
            int newCeilSize = dsu.getSize(maxNode);
            int fall = max(0, newCeilSize - ceilSize - 1);
            ans.push_back(fall);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};