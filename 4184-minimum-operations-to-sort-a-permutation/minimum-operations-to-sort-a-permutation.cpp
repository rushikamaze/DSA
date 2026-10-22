class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int best=INT_MAX;

        int k=nums[0];
        bool okA=true;
        for(int i=0; i<n; i++){
            if(nums[i]!=(i+k)%n){okA=false; break;}
        }
        if(okA){
            if(k==0) best=0;
            else best=min(n-k, k+2);
        }
        int c=nums[0];
        bool okB=true;
        for(int i=0; i<n; i++){
            if(nums[i]!=((c-i)%n+n)%n) { okB=false; break;}
        }
        if(okB){
            int kp=(c+1)%n;
            int cost=(kp==0)?1:min(kp+1, n-kp+1);
            best=min(best, cost);
        }
        return best==INT_MAX ? -1 : best;
    }
};