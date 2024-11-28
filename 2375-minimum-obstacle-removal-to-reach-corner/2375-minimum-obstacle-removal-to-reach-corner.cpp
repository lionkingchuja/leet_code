class Solution {
public:
    bool isvalid(vector<vector<int>>&grid,int row,int col){
        return row >=0 and col >=0 and row< grid.size() and col <grid[0].size();
    }

    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e8));
        
        set<vector<int>>s;
        dist[0][0]=grid[0][0];
        s.insert({dist[0][0],0,0});

        while(!s.empty()){
            vector<int>curr=*s.begin();
            int path=curr[0];int row=curr[1];int col=curr[2];
            s.erase(s.begin());
            if(row==n-1 and col==m-1) return path;

            for(vector<int> i:directions){
                int new_row=row+i[0];int new_col=col+i[1];
                if(isvalid(grid,new_row,new_col)){
                    if(dist[new_row][new_col] > path + grid[new_row][new_col]){
                    dist[new_row][new_col]=path + grid[new_row][new_col];
                    s.insert({dist[new_row][new_col],new_row,new_col});
                    }
                }
                
            }
        }
        return dist[n-1][m-1];
    }
};