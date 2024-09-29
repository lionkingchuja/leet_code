class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            for(int j=0;j<nums.size();j++){
                if(rem==nums[j] and i!=j){
                    ans[0]=i;
                    ans[1]=j;
                    break;
                }
            }
        }
        return ans;
    }
};