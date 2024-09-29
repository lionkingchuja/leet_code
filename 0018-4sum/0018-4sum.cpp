class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1;
                int l=n-1;
                while(k < l){
                    long long sum=nums[i]*1ll+nums[j]*1ll+nums[k]*1ll+nums[l]*1ll;
                    if(sum==target){
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if(sum < target) k++;
                    else l--;

                }

            }
        }
        vector<vector<int>>ans;
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};