class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0);
        for(int num:nums){
            int v=num%k;
            vector<long long> next(k, 0);

            for(int r=0; r<k; r++){
                if(cnt[r]){
                    next[(r*v)%k]+=cnt[r];
                }
            }
            next[v%k]++;
            cnt=next;
            for(int r=0; r<k; r++){
                result[r]+=cnt[r];
            }
        }
        return result;
    }
};