class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        deque <int> r;
        deque <int> d;
        for(int i = n-1 ; i >= 0 ;i--){
            if(senate[i] == 'R') r.push_front(i);
            else d.push_front(i);
        }
        while((!r.empty()) && (!d.empty())){
            if(r.front() < d.front()){
                r.push_back(r.front() + n);
                r.pop_front();
                d.pop_front();
            }else{
                d.push_back(d.front() +n);
                d.pop_front();
                r.pop_front();
            }
        }
        if(r.empty()) return "Dire";
        return "Radiant";
    }
};