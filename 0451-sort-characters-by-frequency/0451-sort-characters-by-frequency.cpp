class Solution {
public:
    string frequencySort(string s) {
        map <char, int> mp;
        for(int i = 0 ; i < s.length() ; i++) mp[s[i]]++;
        priority_queue <pair<int, char>> pq; // max heap
        for(auto it: mp){
            pq.push(make_pair(it.second, it.first));
        }
        string ans = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans.append(it.first, it.second);
        }
        return ans;
    }
};