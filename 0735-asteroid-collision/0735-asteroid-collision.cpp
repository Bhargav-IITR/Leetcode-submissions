class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for(int i = 0 ; i < asteroids.size() ; i++){
            if(asteroids[i] > 0) st.push(asteroids[i]);
            else{
                bool exist = true;
                while(!st.empty() && st.top() <= abs(asteroids[i]) && st.top() > 0){
                    int t = st.top();
                    st.pop();
                    if(t == abs(asteroids[i])){
                        exist = false;
                        break;
                    }
                }
                if(exist && !st.empty() && st.top() > 0) exist = false;
                if(exist) st.push(asteroids[i]);                
            }
        }
        vector <int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};