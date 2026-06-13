class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue <int> pq; // max heap bd
        map <char, int> mp;
        for(char c : tasks) mp[c]++;
        for(auto it : mp) pq.push(it.second);
        queue <pair<int, int>> q;
        int ans = 0;
        while(!pq.empty() || !q.empty()){
            ans++;
            if(!pq.empty()){
                int fq = pq.top();
                pq.pop();
                if(fq-1 > 0){
                    q.push({ans+n, fq-1});
                }
            }            
            if(!q.empty() && (ans == q.front().first)){
                pq.push(q.front().second);
                q.pop();
            }
        }
        return ans;
    }
};