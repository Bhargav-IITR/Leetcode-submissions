#define ll long long
class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        map <string, int> mp;
        for(string s : deadends) mp[s]++;
        string curr = "0000";
        if(curr == target) return 0;
        queue <string> q;
        q.push(curr);
        int ans = 0;
        map <string, int> vis;
        vis[curr] = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string front = q.front();
                q.pop();
                if(mp.find(front) != mp.end()) continue;
                if(front == target) return ans;
                for(int i = 0; i < 4 ; i++){ 
                    char c = front[i]; 
                    // up 
                    front[i] = (c == '9') ? '0' : (c+1); 
                    if((mp.find(front) == mp.end()) && (vis.find(front) == vis.end())) { 
                        vis[front] = 1;
                        q.push(front);
                    } 
                    // down 
                    front[i] = (c == '0') ? '9' : (c-1); 
                    if((mp.find(front) == mp.end()) && (vis.find(front) == vis.end())) { 
                        vis[front] = 1;
                        q.push(front);
                    } 
                    front[i] = c;
                }
            }
            ans++;
        }
        return -1;
    }
};