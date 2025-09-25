class Solution {
public:
    vector<int>dir{-1,0,1};
    int solve(int i,int j1,int j2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(j1<0 or j1>=m or j2<0 or j2>=m) return -1e8;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2] !=-1) return dp[i][j1][j2];
        int maxi=-1e8;
        for(auto a:dir){
            for(auto b:dir){
                if(j1==j2) maxi=max(maxi,grid[i][j1]+solve(i+1,j1+a,j2+b,n,m,grid,dp));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(i+1,j1+a,j2+b,n,m,grid,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,n,m,grid,dp);
    }
};