class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int N = n/2;
        vector <vector <int>> left(N+1), right(N+1); // left,right[i] = vectir of subset sums with subset size i
        //store all possible sums in left and right:
        for(int mask = 0 ; mask < (1<<N) ; mask++){
            int sz = 0, leftSum = 0, rightSum = 0;
            for(int i = 0 ; i < N ; i++){
                if(mask&(1<<i)){
                    sz++;
                    leftSum += nums[i];
                    rightSum += nums[i + N];
                }
                left[sz].push_back(leftSum);
                right[sz].push_back(rightSum);
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0])); // case when initially taken left and right halves give minimum difference
        for(int i = 0 ; i <= N ; i++) sort(right[i].begin(), right[i].end());
        for(int sz = 1 ; sz < N ; sz++){
            for(auto a : left[sz]){
                // do binary search on right[N-sz] to find b such that a+b <= sum/2
                int targetB = (sum-2*a)/2;
                auto ptr = lower_bound(right[N-sz].begin(), right[N-sz].end(), targetB);
                if(ptr != right[N-sz].end()) ans = min(ans, abs(sum - 2*(a+ *ptr)));
                if(ptr != right[N-sz].begin()) ans = min(ans, abs(sum - 2*(a+ *(ptr-1))));
            }
        }
        return ans;
    }
};