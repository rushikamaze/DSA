class Solution {
public:
    int reverseDegree(string s) {
        int result=0;
        for(int i=0; i<(int)s.size(); i++){
            int reversePos=26-(s[i]-'a');
            result+=reversePos*(i+1);
        }
        return result;
    }
};