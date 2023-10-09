class Solution {
public:
    int binary_search(vector<int>&nums,int target,bool flag){
        int l=0;
        int r=nums.size()-1;
        int index=-1;        
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                index=mid;
                if(flag) r=mid-1;
                else l=mid+1;
            }
            else if(nums[mid]> target){
                r=mid-1;
            }
            else if(nums[mid] <target){
                l=mid+1;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans=binary_search(nums,target,true);
        int ans1=binary_search(nums,target,false);
        if(ans==-1){
            return{-1,-1};
        }
        else if(ans==ans1){
            return{ans,ans};
        }
        else{
            return{ans,ans1};
        }
    }
};