class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=nums[i];
            if(a>n)a=a-n;
            if(a>n)a=a-n;
            // cout<<a-1<<":"<< nums[a-1]<<" ";
            
            if(a > 0 && a <= n)nums[a-1] +=n;
        }
        for(auto i:nums) cout<<i<<" ";
        for(int i=0;i<nums.size();i++) if(nums[i]>2*n) return i+1;
        return -1;
    }
};