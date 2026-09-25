class Solution {
public:
    string func(string &s, int &i) {
        string ans = "";
        int n = s.size();

        while (i < n && s[i] != ']') {

            // Normal character
            if (s[i] < '0' || s[i] > '9') {
                ans += s[i];
                i++;
            }

            // Number followed by [...]
            else {
                int k = 0;

                while (i < n && isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }

                // skip '['
                i++;

                string temp = func(s, i);

                // skip ']'
                i++;

                while (k--) {
                    ans += temp;
                }
            }
        }

        return ans;
    }
    string decodeString(string s) {
        int i =0;
        return func(s, i);
    }
};