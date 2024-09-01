class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>&original,int m,int n){
        vector<vector<int>>ans(m,vector<int>(n,0));
        if(m*n != original.size()) return {};
        int div=original.size()/m;
        int j=-1;
        for(int i=0;i <original.size();i++){
            if(i%div ==0 and j+1< m) j++;
            ans[j][i%n]=original[i];
        }
        return ans;
    }
};