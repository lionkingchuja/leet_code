class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            if(target==nums[i]){
                v.push_back(i);
            }
        }
        vector<int>ans(2,-1);
        if(v.size()==0){
            ans[0]=-1;ans[1]=-1;
        }
        else if(v.size()==1){
            ans[0]=v[0];
            ans[1]=v[0];
        }
        else {
            ans[0]=v[0];
            ans[1]=v[v.size()-1];
        }
        return ans;
    }
};