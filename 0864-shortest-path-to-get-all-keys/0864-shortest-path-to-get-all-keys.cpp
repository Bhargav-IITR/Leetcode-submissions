class Solution {
public:
    vector <int> dir = {-1, 0, 1, 0, -1};

    int shortestPathAllKeys(vector<string>& grid) {
        int numKey = 0, startRow = -1, startCol = -1;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z') numKey++;
                else if(grid[i][j] == '@'){
                    startRow = i, startCol = j;
                }
            }
        }

        queue <vector <int>> q;
        q.push({startRow, startCol, 0});
        vector <vector <vector <int>>> vis(m, vector <vector <int>> (n, vector <int> ((1<<6)-1, 0))); // {x,y, keys}
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int s = 0; s < size ; s++){
                auto p = q.front();
                q.pop();
                int x = p[0], y = p[1], keys = p[2];
                if((grid[x][y] >= 'a') && (grid[x][y] <= 'z')) keys |= (1 << (grid[x][y] - 'a'));
                if(keys == ((1 << numKey)-1)){
                    return ans;
                }
                for(int i = 0 ; i < 4 ; i++){
                    int nx = x + dir[i], ny = y + dir[i+1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(grid[nx][ny] == '#') continue;
                    if((grid[nx][ny] == '@') || (grid[nx][ny] == '.') || ((grid[nx][ny] >= 'a') && (grid[nx][ny] <= 'z'))){
                        if(vis[nx][ny][keys]) continue;
                        vis[nx][ny][keys] = 1;
                        q.push({nx, ny, keys});
                        continue;
                    }
                    //now comes locks:
                    if(keys&(1 << (grid[nx][ny]-'A'))){
                        if (vis[nx][ny][keys]) continue;
                        vis[nx][ny][keys] = 1;
                        q.push({nx,ny,keys});
                    }
                }
                
            }
            ans++;
        }

        return -1;
    }
};