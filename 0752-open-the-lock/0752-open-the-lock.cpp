#define ll long long
class Solution {
public:
    int getNum(string &s){
        int ans = 0;
        int pow = 1;
        for(int i = 3 ; i >= 0 ; i--){
            ans +=( (s[i]-'0')*pow);
            pow *= 10;
        }
        return ans;
    }
    int openLock(vector<string>& deadends, string target) {
        vector<int> mp(10000,0);
        for(string s : deadends) mp[getNum(s)] = 1;
        string curr = "0000";
        if(curr == target) return 0;
        queue <string> q;
        q.push(curr);
        int ans = 0;
        vector<int> vis(10000, 0);
        vis[getNum(curr)] = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string front = q.front();
                q.pop();
                if(mp[getNum(front)] != 0) continue;
                if(front == target) return ans;
                for(int i = 0; i < 4 ; i++){ 
                    char c = front[i]; 
                    // up 
                    front[i] = (c == '9') ? '0' : (c+1); 
                    if((mp[getNum(front)] == 0) && (vis[getNum(front)] == 0)) { 
                        vis[getNum(front)] = 1;
                        q.push(front);
                    } 
                    // down 
                    front[i] = (c == '0') ? '9' : (c-1); 
                    if((mp[getNum(front)] == 0) && (vis[getNum(front)] == 0)) { 
                        vis[getNum(front)] = 1;
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