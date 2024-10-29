class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int ans=INT_MAX;
        while(left <=right){
            int mid=(left + right)/2;
            if(nums[mid] >= nums[left]){
                ans=min(ans,nums[left]);
                left=mid+1;
            }
            else if(nums[mid] < nums[right]){
                ans =min(ans,nums[mid]);
                right=mid-1;
            }
        }
        return ans;
    }
};