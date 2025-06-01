class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int left = m-1, right = 0;
        // while(left >= 0 && right < n){
        //     if(nums1[left] > nums2[right]){
        //         swap(nums1[left], nums2[right]);
        //         left--, right++;
        //     }
        //     else break;
        // }
        // sort(nums1.begin(), nums1.begin() + m);
        // sort(nums2.begin(), nums2.end());
        // for(int i = m ; i < m+n; i++){
        //     nums1[i] = nums2[i-m];
        // }
        // // time complexoity = o(nlogn + mlogm);
        


        //gap method:
        if(n == 0) return;
        if(m == 0){
            for(int i = m ;i <m+n;i++) nums1[i] = nums2[i-m];
            return;
        }
        int len = m+n;
        int gap = (len+1)/2;
        while(gap > 0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                if(right < m){
                    if(nums1[left] > nums1[right]) swap(nums1[left], nums1[right]);
                }
                else{
                    if(left < m){
                        if(nums1[left] > nums2[right-m]) swap(nums1[left], nums2[right-m]);
                    }
                    else{
                        if(nums2[left-m] > nums2[right-m]) swap(nums2[left-m], nums2[right-m]);
                    }
                }
                left++, right++;
            }
            if(gap == 1) break;
            gap = (gap+1)/2;
        }
        for(int i =  m; i < m+n ; i++){
            nums1[i] = nums2[i-m];
        }
    }
};