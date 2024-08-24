class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int m=intervals[0].size();

        vector<vector<int>>ans(n,vector<int>(m,-1));
        ans[0][0]=intervals[0][0];
        int curr=intervals[0][1];
        int j=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= curr){
                curr=max(curr,intervals[i][1]);
            }
            else{
                ans[j][1]=curr;
                j++;
                ans[j][0]=intervals[i][0];
                curr=max(curr,intervals[i][1]);
            }
        }
        ans[j][1]=curr;
        vector<vector<int>>final;
        for(int i=0;i<ans.size();i++){
            if(ans[i][0]==-1 and ans[i][1]==-1) break;
            else final.push_back({ans[i][0],ans[i][1]});
        }
        return final;
    }
};