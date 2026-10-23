class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=-1;
        bool any=false;
        for(int i=0; i<(int)nums.size(); i++){
            if(nums[i]!=i){
                ans&=nums[i];
                any=true;
            }
        }
        return any?ans:0;
    }
};