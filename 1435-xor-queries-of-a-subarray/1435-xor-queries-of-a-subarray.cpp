class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries){
        vector<int>v;
        int i=0;
        while(i < queries.size()){
            int l=queries[i][0];
            int r=queries[i][1];
            int ans=arr[l];
            for(int i=l+1;i<=r;i++){
                ans ^=arr[i];
            }
            v.push_back(ans);
            i++;
        }
        return v;
    }
};