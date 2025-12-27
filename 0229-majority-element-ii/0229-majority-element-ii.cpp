class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1 = 0, e2 = 0, c1 = 0, c2 = 0;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            if(c1 == 0 && nums[i] != e2){
                e1 = nums[i];
            }
            if(c2 == 0 && nums[i] != e1){
                e2 = nums[i];
            }
            if(nums[i] == e1) c1++;
            else if(nums[i] == e2) c2++;
            else{
                c1--, c2--;
            }
        }
        vector <int> ans;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == e1) cnt1++;
            else if(nums[i] == e2) cnt2++;
        }
        if(cnt1 > n/3) ans.push_back(e1);
        if(cnt2 > n/3) ans.push_back(e2);
        return ans;
    }
};