class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low <= high){
            int mid=(low+high)/2;
            if(nums[mid]== target) return mid;
            else if(nums[low] <= nums[mid]){//left;
                if(target >= nums[low] and nums[mid] > target) high=mid-1; 
                else low=mid+1;
            }
            else{//right;
                if(nums[high] >= target and target >nums[mid]) low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
};