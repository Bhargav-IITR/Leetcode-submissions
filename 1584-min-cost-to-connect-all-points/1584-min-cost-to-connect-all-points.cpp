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

        int numComp(int zeroOrOneInd, int n){
            int ans = 0;
            int start = (zeroOrOneInd == 1)?1:0;
            int end = (zeroOrOneInd == 1)?n:n-1;
            for(int i = start ; i <= end ; i++){
                ans += (parent[i] == i);
            }
            return ans;
        }
};

class Solution {
public:
    //MST SUM PROBLEM WHERE EDGES ARE ALL NODE CONNECTED TO ALL OTHER AND WEIGHT IS MANHATTAN DISTANCE  
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        priority_queue < pair<int, pair<int, int>> , vector <pair<int, pair<int, int>>>, greater <pair<int, pair<int, int>>>> pq;
        DSU obj(n);
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int xi = points[i][0], yi = points[i][1], xj = points[j][0], yj = points[j][1];
                int md = abs(xi-xj) + abs(yi-yj);
                pq.push({md, {i,j}});
            }
        }
        int ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first, u = it.second.first, v = it.second.second;
            if(obj.findParent(u) != obj.findParent(v)){
                obj.unionByRank(u, v);
                ans += wt;
            }
        }
        return ans;
    }
};