class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int i=0;i<=24;i++){
            int cnt=0;
            for(auto j:candidates){
                cnt +=(j>>i) & 1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};