class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        /*
        bruteforce: t = 0, while(t++){
            check if top left and bottom right are same comp
            if not same-
            traverse(grid){
                node = (i,j)
                go to adj nodes and connect if node and adj node satisfy
            }
        } 
        tc - n^2*n^2 = n^4
        */
        //dijkstra:
        int n = grid.size();
        priority_queue <
            pair<int, pair<int, int>>,
            vector <pair<int, pair<int, int>>>,
            greater <pair<int, pair<int, int>>>
        > pq;
        pq.push({grid[0][0], {0,0}});
        vector <vector <int>> vis(n, vector <int> (n, 0));
        vis[0][0] = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int maxTillNow = it.first;
            int r = it.second.first, c = it.second.second;
            if(r == n-1 && c == n-1) return maxTillNow;
            vector <int> move = {0,1,0,-1,0};
            for(int i = 0 ; i < 4 ; i++){
                int nr = r+move[i], nc = c + move[i+1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
                if(vis[nr][nc] == 1) continue;
                vis[nr][nc] = 1;
                pq.push({max(maxTillNow, grid[nr][nc]), {nr, nc}});
            }
        }
        return -1;
    }
};