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
        int compSize(int node){
            int p = findParent(node);
            return size[p];
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        DSU obj(n*n);
        vector <int> move = {0,1,0,-1,0};
        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< n ; j++){
                if(grid[i][j] == 1){
                    int node = n*i+j;
                    for(int k = 0 ; k < 4 ; k++){
                        int adR = i+move[k], adC = j+move[k+1];
                        if(adR < 0 || adR >= n || adC < 0 || adC >= n) continue;
                        if(grid[adR][adC] == 0) continue;
                        int adNode = adR*n + adC;
                        if(obj.findParent(node) != obj.findParent(adNode)){
                            obj.unionBySize(node, adNode);
                            ans = max(ans, obj.compSize(node));
                        }
                    }
                }
            }
        }
        for(int i = 0 ;i < n; i++){
            for(int j = 0 ; j < n; j++){
                if(grid[i][j] == 0){
                    ans = max(ans, connect(grid, obj, i, j, move));
                }
            }
        }
        return ans;
    }
    int connect(vector <vector <int>> &grid, DSU &obj, int i, int j, vector <int> &move){
        set <int> parent;
        int n = grid.size();
        for(int k = 0 ;k < 4 ;k++){
            int adR = i+move[k], adC = j+move[k+1];
            if(adR < 0 || adR >= n || adC < 0 || adC >= n) continue;
            if(grid[adR][adC] == 0) continue;
            int adNode = adR*n + adC;
            int p = obj.findParent(adNode);
            parent.insert(p);
        }
        int ans= 0;
        if(parent.size() > 0) ans = 1;
        for(auto it : parent){
            ans += obj.compSize(it);
        }
        return ans;
    }
};