class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int M=100000;
        vector<long long> cnt(M+1,0);
        long long total=0;
        int n=nums1.size();
        for(int i=0; i<n; i++){
            int d=abs(nums1[i]-nums2[i]);
            cnt[d]++;
            total+=d;
        }
        long long k=(long long)k1+k2;
        if(total<=k) return 0;

        for(int v=M; v>=1 && k>0; v--){
            if(cnt[v]==0) continue;
            long long c=cnt[v];
            if(c<=k){
                cnt[v-1]+=c;
                cnt[v]=0;
                k-=c;
            } else{
                cnt[v-1]+=k;
                cnt[v]-=k;
                k=0;
            }
        }
        long long ans=0;
        for(long long v=1;v<=M;v++){
            ans+=cnt[v]*v*v;
        }
        return ans;
    }
};