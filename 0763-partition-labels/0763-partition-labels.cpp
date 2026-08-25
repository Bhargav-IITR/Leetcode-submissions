class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        int i = 0, j = 0;
        map <char, int> mp;
        for(int i= 0; i < n; i++) mp[s[i]]++;
        vector <vector <int>> pf(26, vector<int> (n, 0));
        pf[s[0]-'a'][0] = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < 26 ; j++){
                pf[j][i] = pf[j][i-1] + ((s[i]-'a') == j);
            }
        }   
        vector <int> ans;
        while(j < n){
            // check if all characters in the window - i..j - have been used in xcomplete entire occurance
            bool allCheck = true;
            for(char c = 'a' ; c <= 'z' ; c++){
                int count = pf[c-'a'][j] - ((i == 0) ? 0 : pf[c-'a'][i-1]);
                if((count != 0) && (count < mp[c])){
                    allCheck = false;
                    break;
                }
            }
            if(allCheck){
                ans.push_back(j-i+1);
                i = j+1;
            }
            j++;
        }
        return ans;
    }
};