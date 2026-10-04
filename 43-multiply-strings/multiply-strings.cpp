class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";

        int m=num1.size(), n=num2.size();
        vector<int> res(m+n, 0);

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int sum=(num1[i]-'0')*(num2[j]-'0')+res[i+j+1];
                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
            }
        }
        string ans;
        int k=0;
        while(k<res.size() && res[k]==0) k++;
        for(; k<res.size(); k++) ans+=(res[k]+'0');

        return ans;
    }
};