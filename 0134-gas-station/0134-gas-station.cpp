class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int  i =0;
        while(i < n){
            int init = 0;
            int j = i;
            while(j < i+n){
                if(init + gas[j%n] - cost[j%n] >= 0){
                    init += (gas[j%n] - cost[j%n]);
                    j++;
                }else{
                    break;
                }
            }
            if(j == i+n) return i;
            i = j+1;
        }
        return -1;
    }
};