class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            nums[i] %=2;
        }
        //The problem becomes finding the number of subarrays that sum to k
        //with the modified nums array.


        vector<int>prefix(nums.size()+1);
        prefix[0]=1;
        int sum=0;int ans=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            ans +=(sum >=k) ? prefix[sum-k]:0;
            prefix[sum]++;
            cout<<ans<<" ";
        }
        return ans;
    }
};