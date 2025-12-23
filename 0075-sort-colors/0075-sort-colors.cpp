class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int lo = 0, mid = 0, hi = nums.size()-1;
        // while(mid <= hi){
        //     if(nums[mid] == 0) {
        //         swap(nums[lo], nums[mid]);
        //         mid++, lo++;
        //     }
        //     else if(nums[mid] == 1) mid++;
        //     else {
        //         swap(nums[mid], nums[hi]);
        //         hi--;
        //     }
        // }
        // DNF sort algorithm
        int lo = 0 , mid = 0, hi = nums.size()-1;
        /*
        section 0->lo-1 -----> all 0
        section lo->mid-1 -----> all 1
        section mid->hi ------> unsorted 0s 1s 2s
        section hi+1->n-1 -------> all 2
        ------------> basis of algo
        */
        while(mid <= hi){
            if(nums[mid] == 0){
                swap(nums[lo], nums[mid]);
                mid++, lo++;
            }else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[hi]);
                hi--;
            }
        }
    }
};