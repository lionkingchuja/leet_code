class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>v[n];
        for(int i=0;i<roads.size();i++){
            v[roads[i][0]].push_back(roads[i][1]);
            v[roads[i][1]].push_back(roads[i][0]);
        }
        vector<long long>temp;
        for(int i=0;i<n;i++)  temp.push_back(v[i].size());
        sort(temp.rbegin(),temp.rend());
        long long ans=0;
        long long j=n;
        for(int i=0;i<temp.size();i++){
            ans +=(temp[i]*j);
            j--;
        }
        return ans;
    }
};