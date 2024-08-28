class Solution {
public:
    bool isans=true;
    void solve(int i,int j,vector<vector<int>>&grid1,vector<vector<int>>&grid2,vector<vector<bool>>&vis){
        int n=grid2.size();
        int m=grid2[0].size();
        if(i>=n or j>=m or i<0 or j<0 or vis[i][j]==true or grid2[i][j]==0) return;
        if(grid2[i][j]==1 and grid1[i][j]==0) {
            isans=false;
        }

        vis[i][j]=true;
        solve(i+1,j,grid1,grid2,vis);
        solve(i-1,j,grid1,grid2,vis);
        solve(i,j+1,grid1,grid2,vis);
        solve(i,j-1,grid1,grid2,vis);

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 and vis[i][j]==false){
                    solve(i,j,grid1,grid2,vis);
                    cnt+=isans;
                    isans = true;
                }
            }
        }
        return cnt;
    }
};