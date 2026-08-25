class Solution {
public:
    string predictPartyVictory(string senate) {
        deque <char> dq;
        int n = senate.length();
        for(int i = n-1 ; i >= 0; i--) dq.push_front(senate[i]);
        while(true){
            char c = dq.front();
            dq.pop_front();
            queue <char> temp;
            while(!dq.empty() && (dq.front() == c)){
                temp.push(dq.front());
                dq.pop_front();
            }
            if(dq.empty()) return ((c == 'R') ? "Radiant" : "Dire");
            dq.pop_front();
            while(!temp.empty()) {
                dq.push_front(temp.front());
                temp.pop();
            }
            dq.push_back(c);
        }
        return "";
    }
};