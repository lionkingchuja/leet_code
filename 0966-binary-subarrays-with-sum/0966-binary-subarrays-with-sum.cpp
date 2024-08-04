class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        int sum=0;
        int ans=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            if(m.find(sum-goal) !=m.end()){
                ans +=m[sum-goal];
                m[sum]++;
            }
            else m[sum]++;
        }
        return ans;
    }
};