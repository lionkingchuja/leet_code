class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int mi=a[0][0];
        int mx=a[0][a[0].size()-1];
        int ans=0;
        for(int i=1;i<a.size();i++){
            int lmi=a[i][0];
            int lmx=a[i][a[i].size()-1];
            
            ans=max(ans,max(lmx-mi,mx-lmi));
            mi=min(mi,lmi);
            mx=max(mx,lmx);
        }
        return ans;
    }
};