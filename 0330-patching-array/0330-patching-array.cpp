class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i=0;
        long long sum=1;
        int ans=0;
        while(sum <=n){
            if(i<nums.size() and nums[i] <= sum) {
                sum +=nums[i++];
            }
            else sum +=sum;
            ans++;
        }
        cout<<ans<<" "<<i;
        return ans-i;
    }
};