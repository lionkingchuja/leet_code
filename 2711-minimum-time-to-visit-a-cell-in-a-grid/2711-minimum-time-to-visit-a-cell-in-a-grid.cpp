class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[1][0] >1 and grid[0][1] > 1) return -1;

        vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        set<vector<int>>s;
        s.insert({grid[0][0],0,0});

        while(!s.empty()){
            vector<int>temp=*s.begin();
            int time=temp[0];int row=temp[1];int col=temp[2];
            s.erase(*s.begin());
            if(row==n-1 and col==m-1) return time;

            if(visited[row][col]) continue;
            visited[row][col]=true;

            for(auto dir:directions){
                int next_row=row+dir[0];
                int next_col=col+dir[1];
                if(next_row <0 or next_col <0 or next_row >=n or next_col >=m) continue;

                if(grid[next_row][next_col] <=time+1){
                    s.insert({time+1,next_row,next_col});
                }
                else{
                    int diff=grid[next_row][next_col]-time;
                    if((diff % 2)==0) s.insert({grid[next_row][next_col]+1,next_row,next_col});
                    else s.insert({grid[next_row][next_col],next_row,next_col});
                }
            }
        }
        return -1;
    }
};