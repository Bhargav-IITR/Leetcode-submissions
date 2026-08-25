class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector <int> comp = {INT_MIN, INT_MIN, INT_MIN};
        for (auto &t : triplets) {
            if (t[0] <= target[0] &&
                t[1] <= target[1] &&
                t[2] <= target[2]) {

                comp[0] = max(comp[0], t[0]);
                comp[1] = max(comp[1], t[1]);
                comp[2] = max(comp[2], t[2]);
            }
        }
        return comp == target;
    }
};