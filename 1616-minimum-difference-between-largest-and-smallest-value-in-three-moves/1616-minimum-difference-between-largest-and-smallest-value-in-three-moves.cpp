class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n <=4) return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        //case-1 all three smallest
        ans=min(ans,nums[n-1]-nums[3]);
        //case-2 2 smallest 1 largest
        ans=min(ans,nums[n-2]-nums[2]);
        //case-3 1 smallest 2 largest
        ans=min(ans,nums[n-3]-nums[1]);
        //case-4 all three largest
        ans=min(ans,nums[n-4]-nums[0]);
        return ans;
    }
};