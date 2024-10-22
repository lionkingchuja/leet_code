class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int k=j+1;
                int l=nums.size()-1;
                while(k <l){
                    long long temp=nums[i]+nums[j]+nums[k]+nums[l];
                    if(temp==target){
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if(temp > target) l--;
                    else k++;
                }
            }
        }
        
        vector<vector<int>>ans;
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};