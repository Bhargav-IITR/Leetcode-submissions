class DSU{
    vector <int> parent, rank;
    
    public:
        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1, 0);
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
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU obj(n*n);
        map <int, pair<int,int>> coord;
        for(int i = 0; i <n ;i++){
            for(int j = 0; j< n; j++){
                coord[grid[i][j]] = {i,j};
            }
        }
        int startNode = 0, endNode = n*n-1;
        for(auto it : coord){ //traversingin increasing order of heights -> increasing time
            int height = it.first; // this height gets submerged now so connect it with neghbouring submeerged cells
            int r = it.second.first;
            int c = it.second.second;
            int node = r*n + c;
            // nhi hua to connect with 4 dir cells
            vector <int> move = {0,1,0,-1,0};
            for(int i = 0 ; i < 4 ; i++){
                int nr = r + move[i], nc = c + move[i+1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if(grid[nr][nc] > height) continue;
                int adNode = nr*n + nc;
                obj.unionByRank(node, adNode);
            }
            if(obj.findParent(endNode) == obj.findParent(startNode)) return height;
        }
        return -1;
    }
};