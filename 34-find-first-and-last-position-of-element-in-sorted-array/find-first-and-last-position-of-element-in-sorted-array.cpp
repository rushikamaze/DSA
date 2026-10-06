class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lowerBound(nums, target);
        if(first==nums.size()||nums[first]!=target) return {-1,-1};

        int last=lowerBound(nums, target+1)-1;
        return{first, last};
    }
    private:
    int lowerBound(const vector<int>& nums, long long x){
        int left=0; int right=nums.size();
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<x) left=mid+1;
            else right=mid;
        }
        return left;
    }
};