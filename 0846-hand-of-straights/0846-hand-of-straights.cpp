class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        int n = hand.size();
        if((n%groupSize) != 0) return false;
        map <int, int> mp;
        for(int num : hand) mp[num]++;  
        vector <int> vis(n, 0);
        map <int, int> firstId;
        for(int i = 0; i< n ; i++){
            if(firstId.find(hand[i]) == firstId.end()) firstId[hand[i]] = i;
        }
        for(int i = 0 ; i < n ; i++){
            if(vis[i]) continue;
            int num = hand[i];
            while(num <= hand[i] + groupSize-1){
                auto it = lower_bound(hand.begin(), hand.end(), num);
                if(it == hand.end()) return false;
                if(*it != num) return false;
                if(mp[num] == 0) return false;   
                vis[firstId[num]] = 1;
                firstId[num]++;
                mp[num]--; 
                num++;
            }
        }
        return true;
    }
};