class Solution {
public:
    int solve(int m,vector<int>& nums){
        int l=0;
        int r=0;
        int cnt=0;
        while(r<nums.size()){
            while(r> l and nums[r]-nums[l] >m) l++;
            cnt +=r-l;
            r++;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums[nums.size()-1]-nums[0];
        while(l<r){
            int mid=(l+r)/2;
            if(solve(mid,nums) < k) l=mid+1;
            else r=mid;
        }
        return l;
    }
};