class Solution {
public:
    int maxmsubarrlen(int k,vector<int>&nums){
        // cannot use two pointer due to k is negative.
        int max_len=0;
        int sum=0;
        unordered_map<int,int>m;
        // m[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            if(sum ==k) max_len=max(max_len,i+1);
            else if(m.find(sum-k) !=m.end()){
                max_len=max(max_len,i-m[sum-k]);
            }
            m[sum]=i;
        }
        return max_len;
    }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        int rem=total_sum - x;
        if(rem==0) return n;
        
        int res=maxmsubarrlen(rem,nums);
        if(res==0) return -1;
        return n-res;
    }
};