class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = n-1;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(arr[mid] == target) return mid;
            if(arr[0] < arr[n-1]){ // not rotated
                if(target < arr[mid]) j = mid-1;
                else i = mid+1;
            }else{
                if(arr[mid] < arr[0]){ // right half
                    if(target > arr[mid] && target < arr[0]) i = mid+1;
                    else j = mid-1;
                }else{ // left half
                    if(target < arr[mid] && target > arr[n-1]) j = mid-1;
                    else i = mid+1;
                }
            }
        }
        return -1;
    }
};