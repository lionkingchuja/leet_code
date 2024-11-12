class Solution {
public:
    int binary_s(vector<vector<int>>& items, int x){
        int left=0;
        int right=items.size()-1;
        int ans=0;
        while(left <= right){
            int mid=(left+right)/2;
            if(items[mid][0] <=x){
                ans=max(items[mid][1],ans);
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int mx=INT_MIN;
        for(int i=0;i<items.size();i++){
            mx=max(items[i][1],mx);
            items[i][1]=mx;
        }

        vector<int>ans;
        for(int i=0;i< queries.size();i++){
            int b_s=binary_s(items,queries[i]);
            ans.push_back(b_s);
        }
        return ans;
    }
};