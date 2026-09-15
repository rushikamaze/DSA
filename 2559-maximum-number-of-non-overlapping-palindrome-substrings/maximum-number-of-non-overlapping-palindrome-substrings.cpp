class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k>n) return 0;

        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(s[i]==s[j]){
                    if(j-i<2){
                        isPal[i][j]=true;
                    } else {
                        isPal[i][j]=isPal[i+1][j-1];
                    }
                }
            }
        }
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++){
            dp[i]=dp[i-1];
            if(i-k>=0 && isPal[i-k][i-1]){
                dp[i]=max(dp[i], dp[i-k]+1);
            }
            if(i-k-1>=0 && isPal[i-k-1][i-1]){
                dp[i]=max(dp[i], dp[i-k-1]+1);
            }
        }
        return dp[n];
    }
};