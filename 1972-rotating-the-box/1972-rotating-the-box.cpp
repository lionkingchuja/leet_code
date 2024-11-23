class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=box[j][i];
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n/2;j++){
                swap(ans[i][j],ans[i][n-1-j]);
            }
        }

        for(int i=m-1;i >=0;i--){
            for(int j=0;j<n;j++){
                if(ans[i][j]=='#'){
                    for(int k=i+1;k<m;k++){
                        if(ans[k][j]=='.'){
                            ans[k-1][j]='.';
                            ans[k][j]='#';
                        }
                        else if(ans[k][j]=='*') break;
                    }
                }
            }
        }
       
        return ans;
    }
};