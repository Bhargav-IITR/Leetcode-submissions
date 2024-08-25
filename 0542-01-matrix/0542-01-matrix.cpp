class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector <vector <int>> vis(m, vector <int> (n,0));
        vector <vector <int>> dist(m, vector <int> (n, 0));

        queue <pair <pair <int,int>,int>> q;

        for(int i =0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
                else vis[i][j] = 0;
            }
        }
        vector<pair<int,int>> moves = {{1,0}, {-1,0}, {0, 1}, {0,-1}};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            dist[row][col] = steps;
            q.pop();
            for(auto e : moves){
                int nrow = row + e.first;
                int ncol = col + e.second;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol}, steps+1});
                }
            }
        }
        return dist;
    }
};