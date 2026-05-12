class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort by buffer (min - actual) descending
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int ans = 0, cur = 0;
        for (auto& t : tasks) {
            int actual = t[0], minimum = t[1];
            if (cur < minimum) {
                ans += minimum - cur;
                cur = minimum;
            }
            cur -= actual;
        }
        return ans;
    }
};