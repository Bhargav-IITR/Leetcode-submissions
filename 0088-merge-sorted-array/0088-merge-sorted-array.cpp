class Solution {
public:
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     //GAP METHOD:
    //     int gap = (m+n+1)/2;
    //     while(gap > 0){
    //         int i = 0, j = i+gap;            
    //         while(j < m+n){
    //             if(i < m && j >= m){ // n1 & n2
    //                 if(nums1[i] > nums2[j-m]){
    //                     swap(nums1[i], nums2[j-m]);
    //                 }
    //             }else if(j < m){ // n1 & n1
    //                 if(nums1[i] > nums1[j]){
    //                     swap(nums1[i], nums1[j]);
    //                 }
    //             }else{ // n2 & n2
    //                 if(nums2[i-m] > nums2[j-m]){
    //                     swap(nums2[i-m], nums2[j-m]);
    //                 }
    //             }
    //             i++, j++;
    //         }            
    //         if(gap == 1) break;
    //         gap = (gap+1)/2;
    //     }
    //     for(int i = m ; i < n+m ; i++) nums1[i] = nums2[i-m];
    // }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m+n-1;
        int i = m-1, j = n-1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[last] = nums1[i];
                i--;
            }else{
                nums1[last] = nums2[j];
                j--;
            }
            last--;
        }
        while(j >= 0){
            nums1[last] = nums2[j];
            last--, j--;
        }
    }
};