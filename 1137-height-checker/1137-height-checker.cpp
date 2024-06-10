class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>final=heights;
        sort(heights.begin(),heights.end());
        int ans=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i] != final[i]) ans++;
        }
        return ans;
    }
};