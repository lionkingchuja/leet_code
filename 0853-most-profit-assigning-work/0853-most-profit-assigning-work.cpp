class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> temp;
        for(int i = 0; i < difficulty.size();i++) {
            temp.push_back({difficulty[i], profit[i]});
        }
        sort(temp.begin(),temp.end());
        sort(worker.begin(),worker.end());
        int res=0;
        int j=0;
        int ans=0;
        for(auto i:worker){
            while(j< worker.size() and i >= temp[j].first){
                ans =max(ans,temp[j].second);
                j++;
            }
            cout<<ans<<" ";
            res +=ans;
        }
        return res;
    }
};