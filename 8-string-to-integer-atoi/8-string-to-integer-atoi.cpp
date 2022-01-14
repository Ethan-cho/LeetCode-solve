class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int base = 0;
        int i = 0;
        int n = s.size();
        while(i < n && s[i] == ' '){
             i++;
        }
        if(s[i] == '-' || s[i] == '+') sign = 1 - 2*(s[i++] =='-');
        while(s[i] >= '0' && s[i] <='9'){
           if(base > INT_MAX/10 || base == INT_MAX/10 && s[i]- '0' > INT_MAX %10){
              if(sign == 1)return INT_MAX;
                 return INT_MIN;
              }
             base = (base * 10) + (s[i++] - '0');
           }
        return base * sign;
    }
};