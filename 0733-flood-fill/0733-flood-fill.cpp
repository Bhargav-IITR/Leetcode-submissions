class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector <vector <int>> vis(m, vector <int> (n, 0)); 
        queue <pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        while(!q.empty()){
            int size = q.size();
            for(int node = 1 ; node <= size ; node++){
                auto f = q.front();
                q.pop();
                int i = f.first, j = f.second;
                int startClr = image[i][j];
                image[i][j] = color;
                if(i-1 >= 0 &&  image[i-1][j] == startClr && vis[i-1][j] == 0){
                    q.push({i-1,j});
                    vis[i-1][j] = 1;
                }
                if(i+1 < m &&  image[i+1][j] == startClr && vis[i+1][j] == 0){
                    q.push({i+1,j});
                    vis[i+1][j] = 1;
                }
                if(j-1 >= 0 && image[i][j-1] == startClr && vis[i][j-1] == 0){
                    q.push({i,j-1});
                    vis[i][j-1] = 1;
                }
                if(j+1 < n && image[i][j+1] == startClr && vis[i][j+1] == 0){
                    q.push({i,j+1});
                    vis[i][j+1] = 1;
                }
            }
        }
        return image;
    }
};