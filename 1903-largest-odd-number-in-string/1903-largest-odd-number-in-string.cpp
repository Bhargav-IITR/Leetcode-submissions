class Solution {
public:
    string largestOddNumber(string num) {
        while(num.length() != 0 && (num[num.length()-1]-'0')%2 == 0){
            num.pop_back();
        }
        if(num.length() == 0) num = "";
        return num;
    }
};