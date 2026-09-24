class Solution {
public:
    int myAtoi(string s) {
        int i=0, n=s.size();
        while(i<n && s[i] == ' ') i++;

        int sign=1;
        if(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        long result=0;
        while(i<n && isdigit(s[i])){
            result=result*10+(s[i]-'0');
            if(sign == 1 && result>INT_MAX){
                result=INT_MAX;
                break;
            }
            if(sign == -1 && -result<INT_MIN){
                result=-(long)INT_MIN;
                break;
            }
            i++;
        }
        return (int)(sign*result);
    }
};