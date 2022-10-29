class Solution {
public:
    int myAtoi(string s) {
        const int len = s.size();
        if(len == 0){
            return 0;
        }      
        int index = 0;
        while(index < len && s[index] == ' '){
            ++index;
        }
        if(index == len){
            return 0;
        }
        char ch;
        bool isNegative = (ch = s[index]) == '-';
        if(isNegative || ch == '+'){
            ++index;
        }	
        const int maxLimit = INT_MAX / 10;
        int result = 0;
        while(index < len && s[index]>='0'&&s[index]<='9'){ 
            int digit = s[index] - '0';
            if(result > maxLimit || (result == maxLimit && digit > 7)){
                return isNegative ? INT_MIN : INT_MAX;
            }
            result = (result * 10) + digit;
            ++index;
        }
        return isNegative ? -result : result;
    }
};