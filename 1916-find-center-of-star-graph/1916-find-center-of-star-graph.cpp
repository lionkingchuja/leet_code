class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        map<int,int>m;
        for(int i=0;i<n;i++) {
            m[edges[i][0]]++;
            m[edges[i][1]]++;
        }
        for(auto i:m){
            if(i.second >=n) return i.first;
        }
        return -1;
    }
};