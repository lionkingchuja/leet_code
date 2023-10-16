class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        int n=nums.size();
        vector<pair<int,int>>vp(n);
        vp[n-1].first=nums[n-1];
        vp[n-1].second=nums[n-1];
        for(int i=n-2;i>=0;i--){
            vp[i].first=max(nums[i],vp[i+1].first);
            vp[i].second=min(nums[i],vp[i+1].second);
        }
        vector<int>ans(2,-1);
        for(int i=0;i<n;i++){
            int j=i+id;
            if(j<n and (abs(nums[i]-vp[j].first) >=vd or abs(nums[i]-vp[j].second) >=vd)){
                ans[0]=i;
                for(int k=j;k<n;k++){
                    if(abs(nums[i]-nums[k])>=vd){
                        ans[1]=k;
                        return ans;
                    }
                }
                //break;
            }
        }
        return {-1,-1};
    }
};