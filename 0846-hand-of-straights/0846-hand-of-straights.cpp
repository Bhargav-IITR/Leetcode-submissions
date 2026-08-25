class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        int n = hand.size();
        if((n%groupSize) != 0) return false;
        map <int, int> mp;
        for(int num : hand) mp[num]++;  
        while(!mp.empty()){
            int lowestCard = (*mp.begin()).first;
            int temp = lowestCard;
            while(temp <= lowestCard + groupSize-1){
                if(mp[temp] > 0){
                    mp[temp]--;
                    if(mp[temp] == 0) mp.erase(temp);
                }else return false;
                temp++;
            }
        }
        return true;
    }
};