class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long add=nums[i]*1ll+nums[j]*1ll+nums[k]*1ll+nums[l]*1ll;
                    if(add==target) {
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if(add < target) k++;
                    else if(add > target) l--;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};