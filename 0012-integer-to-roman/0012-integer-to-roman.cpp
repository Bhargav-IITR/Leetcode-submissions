class Solution {
public:
    const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
    string intToRoman(int num) {
        if(num == 0) return "";
        string ans = "";
        for(auto it : valueSymbols){
            if(num == 0) break;
            if(num >= it.first){
                int times = num/it.first;
                while(times--){
                    ans += it.second;
                    num -= it.first;
                }
            }
        }
        return ans;
    }
};