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
    vector <int> dir = {-1, 0, 1, 0, -1};
    int nodeNum(int i, int j, int n){
        return i*n+j;
    }
    bool func(vector<vector <int>> &sfGrid, int sf){
        int n = sfGrid.size();
        DSU dsu(n*n);
        if(sfGrid[0][0] < sf || sfGrid[n-1][n-1] < sf) return false;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n ; j++){
                if(sfGrid[i][j] < sf) continue;
                for(int k = 0 ; k < 4 ; k++){
                    int ni = i + dir[k], nj = j + dir[k+1];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < n && sfGrid[ni][nj] >= sf) dsu.unionByRank(nodeNum(i,j, n), nodeNum(ni, nj, n));
                }
            }
        }
        return dsu.findParent(nodeNum(0,0,n)) == dsu.findParent(nodeNum(n-1,n-1,n));
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n= grid.size();
        int lo = 0, hi = 2*n-2;
        int ans;
        //first build 2d vector corresponding to grid representing min MH from each cell to another thief cell using BFS
        vector <vector <int>> sfGrid = buildsf(grid);
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(func(sfGrid, mid)){ // func -> true if there exists a path from 0,0 to n-1,n-1 in which SF = mid
                ans = mid;
                lo = mid+1;
            }else hi = mid-1; 
        }
        return ans;
    }

    vector <vector<int>> buildsf(vector<vector<int>> &grid){
        int n = grid.size();
        vector <vector <int>> dist (n, vector <int> (n, INT_MAX)) ;
        vector <vector <int>> vis(n, vector <int> (n, 0));
        queue <pair<int,int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }
        int lvl = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto front = q.front();
                q.pop();
                int i = front.first , j = front.second;
                for(int k = 0 ; k < 4 ; k++){
                    int ni = i + dir[k], nj = j + dir[k+1];
                    if((ni >= 0) && (ni < n) && (nj >= 0) && (nj < n) && (vis[ni][nj] == 0)){
                        dist[ni][nj] = lvl;
                        vis[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
            lvl++;
        }
        return dist;
    }
};
