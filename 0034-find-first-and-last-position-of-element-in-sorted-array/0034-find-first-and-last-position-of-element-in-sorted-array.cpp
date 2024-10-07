class Solution {
public:
    int solve(vector<int>&nums,int target){
        int low=0,high=nums.size()-1;
        while(low <=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid] > target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int find=solve(nums,target);
        if(find==-1) return{-1,-1};
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int y=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {x,y-1};
    }
};