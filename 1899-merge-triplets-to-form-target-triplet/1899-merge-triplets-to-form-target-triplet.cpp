class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        map <int,int> mp;
        for(int i = 0 ; i < n; i++){
            if(triplets[i][0] <= target[0]) mp[i]++;
            if(triplets[i][1] <= target[1]) mp[i]++;
            if(triplets[i][2] <= target[2]) mp[i]++;
        }
        vector <int> comp = {INT_MIN, INT_MIN, INT_MIN};
        for(auto it : mp){
            if(it.second == 3){
                int id = it.first;
                comp = {max(comp[0], triplets[id][0]), max(comp[1], triplets[id][1]), max(comp[2], triplets[id][2])};
            }
        }
        return comp == target;
    }
};