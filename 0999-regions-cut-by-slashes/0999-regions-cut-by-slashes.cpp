class Solution {
public:
    void dfs(int i,int j, vector<vector<int>>&new_grid,vector<vector<bool>>&visited){
        int n=new_grid.size();
        if(i<0 or j<0 or i>=n or j>=n or new_grid[i][j]==0 or visited[i][j]==true) return;
        visited[i][j]=true;
        dfs(i,j+1,new_grid,visited);
        dfs(i+1,j,new_grid,visited);
        dfs(i,j-1,new_grid,visited);
        dfs(i-1,j,new_grid,visited);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>>new_grid(n*3,vector<int>(n*3,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    new_grid[3*i][3*j+2]=0;
                    new_grid[3*i+1][3*j+1]=0;
                    new_grid[3*i+2][3*j]=0;
                }
                else if(grid[i][j]=='\\'){
                    new_grid[3*i][3*j]=0;
                    new_grid[3*i+1][3*j+1]=0;
                    new_grid[3*i+2][3*j+2]=0;
                }
            }
        }
        vector<vector<bool>>visited(n*3,vector<bool>(n*3,false));
        int ans=0;
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(new_grid[i][j]==1 and visited[i][j]==false){
                    dfs(i,j,new_grid,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};