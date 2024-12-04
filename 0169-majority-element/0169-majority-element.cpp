class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // // moore's algorithm
        // int can = -1, cnt = 0;
        // for(int i = 0 ; i < nums.size(); i++){
        //     if(cnt == 0){
        //         can = nums[i];
        //         cnt++;
        //     }
        //     else{
        //         if(nums[i] == can) cnt++;
        //         else cnt--;
        //     }
        // }
        // cnt = 0;
        // for(int i = 0 ; i < nums.size(); i++) cnt += (nums[i] == can);
        // if(cnt > nums.size()/2) return can;
        // return -1;
        int num = nums[0];
        int cnt = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != num){
                cnt--;
                if(cnt == 0){
                    cnt = 1;
                    num = nums[i];
                }
            }else cnt++;
        }
        cnt = 0;
        for(int i = 0 ; i < nums.size() ; i++) cnt += (nums[i] == num);
        if(cnt > nums.size()/2) return num;
        return -1;
    }
};