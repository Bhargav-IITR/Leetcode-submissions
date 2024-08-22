
class DisjointSet{
    vector <int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0 ; i <= n ; i++) parent[i] = i; 
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        //we have node u and node v which have to be
        //combined
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    //time complexity = O(4*alpha) == O(constant); 
};

class Solution {
public:
    bool isVal(int i, int j, int n, int m){
        return (i < n && j < m && i >= 0 && j >= 0);
    }

    int numIslands(vector<vector<char>>& grid) {
        int nxt = 1;
        int n = grid.size(), m = grid[0].size();
        vector <vector <int>> list(n, vector <int> (m, 0));
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1') list[i][j] = nxt;
                else list[i][j] = 0;
                nxt++;
            }
        }

        vector <pair <int,int>> moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        DisjointSet ds(n*m);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(list[i][j] != 0){
                    for(auto e : moves){
                        int ni = i + e.first;
                        int nj = j + e.second;
                        if(isVal(ni, nj, n, m) && list[ni][nj] != 0){
                            ds.unionByRank(list[i][j], list[ni][nj]);
                        }
                    }
                }
            }
        }

        set <int> st;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(list[i][j] != 0){
                    int par = ds.findParent(list[i][j]);
                    st.insert(par);
                }
            }
        }
        return st.size();
    }
};