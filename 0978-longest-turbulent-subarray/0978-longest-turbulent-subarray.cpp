class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        if(n == 2) return ((arr[0] == arr[1]) ? 1 : 2);
        int go = -1;
        int start = 0;
        int ans = 1;
        for(int i = 0 ; i < n-1 ; i++){
            if(go == -1){
                if(arr[i+1] > arr[i]){
                    go = 0; 
                    ans = max(ans, 2);
                }else if(arr[i+1] < arr[i]){
                    go = 1;
                    ans = max(ans, 2);
                }else {
                    start = i+1;
                }
            }else{
                if(go == 1) {
                    if(arr[i+1] > arr[i]){
                        go = 0;
                        ans = max(ans, i+2-start);
                    }else if(arr[i+1] < arr[i]){
                        ans = max(ans, i-start + 1);
                        start = i;
                    }else {
                        ans = max(ans, i-start+1);
                        start = i+1;
                    }
                }else{
                    if(arr[i+1] < arr[i]){
                        go = 1;
                        ans = max(ans, i+2-start);
                    }else if(arr[i+1] > arr[i]){
                        ans = max(ans, i-start+1);
                        start = i;
                    }else{
                        ans = max(ans, i-start+1);
                        start = i+1;
                    }
                }
            }
        }
        return ans;
    }
};