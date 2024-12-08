class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();

        int mx=events[n-1][2];
        vector<int>v,pre(n,mx);
        for(int i=n-2;i>=0;i--){
            if(events[i][2] >mx){
                mx=events[i][2];
            }
            pre[i]=mx;
        }

        for(auto i:events){
            v.push_back(i[0]);
        }
        for(auto i:v) cout<<i<<" ";

        int ans=0;
        for(int i=0;i<n;i++){
            int val=events[i][1];
            int y=upper_bound(v.begin(),v.end(),val)-v.begin();
            ans=max(ans,events[i][2]);
            if(y==n) continue;
            ans=max(ans,events[i][2]+pre[y]);
        }
        return ans;
    }
};