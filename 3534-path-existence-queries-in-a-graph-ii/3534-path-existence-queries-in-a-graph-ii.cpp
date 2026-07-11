class Solution {
public:
    int upperBound(vector<pair<int, int>> &arr, int X){
        int N = arr.size();
        int low = 0, high = N;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid].first <= X)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector <pair<int, int> > a;
        for(int i = 0 ; i < n ; i++) a.push_back({nums[i], i});
        sort(a.begin(), a.end());
        map <int, int> mapping;
        for(int i = 0; i < n ; i++){
            int org = a[i].second;
            mapping[org] = i;
        }
        vector<int> next(n);

        for (int i = 0; i < n; i++){
            next[i] = upperBound(a, a[i].first + maxDiff) - 1;
        }
        //binary lifting
        int lg = 18;
        vector <vector <int> > binLift(lg, vector <int> (n, -1)); 
        vector <int> ans;
        for(int i= 0 ; i < n ; i++) binLift[0][i] = next[i];
        for(int k = 1 ; k < lg ; k++){
            for(int i = 0;i < n; i++){
                binLift[k][i] = binLift[k-1][binLift[k-1][i]];
            }
        }
        for(auto query : queries){
            int ui = min(mapping[query[0]], mapping[query[1]]), vi = max(mapping[query[0]], mapping[query[1]]);
            int i = ui;
            if(ui == vi) {
                ans.push_back(0);
                continue;
            }
            // find the max binary jump that'll lead to a jump from ui to a point just less than or equal to vi
            //start with max jump
            int steps = 0; 
            for(int k = lg-1 ; k >= 0 ; k--){
                if(binLift[k][i] > i && binLift[k][i] < vi){
                    i = binLift[k][i];
                    steps += (1<<k);
                }
            }
            if(next[i] >= vi){
                steps++;
            }else {
                steps = -1;
            }
            ans.push_back(steps);
        }
        return ans;
    }
};