class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&visited){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0 or visited[i][j]==true) return;
        visited[i][j]=true;
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);
    }
    int cnt(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and visited[i][j]==false){
                    dfs(i,j,grid,visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        
        if(cnt(grid) !=1) return 0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0; //remove the land cell
                    if(cnt(grid) !=1) return 1;
                    grid[i][j]=1; // restore the land cell
                }
            }
        }
        return 2;
    }
};