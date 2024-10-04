class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(auto i:nums) sum +=i;
        if(sum < p) return -1;
        if(sum %p==0) return 0;
        int rem=sum%p;

        long long prefix=0;
        unordered_map<int,int>m;
        int ans=INT_MAX;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            prefix +=nums[i];
            int curr=prefix %p;
            int diff=(curr-rem +p) %p;
            if(m.find(diff) !=m.end()){
                ans=min(ans,i-m[diff]);
            }
            m[curr]=i;
        }
        return ans==nums.size() ?-1:ans;
    }
};