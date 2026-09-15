class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        
        for(int num:nums){
            count[num]++;
        }
        for(int i=1; i<=100; i++){
            count[i]+=count[i-1];
        }
        vector<int> result(nums.size());
        for(int i=0; i<nums.size(); i++){
            result[i]=(nums[i]==0)?0:count[nums[i]-1];
        }
        return result;
    }
};