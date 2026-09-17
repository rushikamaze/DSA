class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> dp(n, INT_MAX);
        int left=0, sum=0;
        int ans=INT_MAX;

        for(int right=0; right<n; right++){
            sum+=arr[right];

            while(sum>target){
                sum-=arr[left];
                left++;
            }
            if(sum==target){
                int currLen=right-left+1;
                if(left>0 && dp[left-1] != INT_MAX){
                    ans=min(ans, dp[left-1]+currLen);
                }
                dp[right]=(right>0)?min(dp[right-1], currLen):currLen;
            } else {
                dp[right]=(right>0) ? dp[right-1]:INT_MAX;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};