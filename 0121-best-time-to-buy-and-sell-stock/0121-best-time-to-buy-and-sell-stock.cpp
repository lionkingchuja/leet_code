class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(mi > prices[i]) mi=prices[i];
            ans=max(ans,prices[i]-mi);
        }
        return ans;
    }
};