class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>&original,int m,int n){
        vector<vector<int>>ans(m,vector<int>(n,0));
        if(m*n != original.size()) return {};
        int j=-1;
        for(int i=0;i <original.size();i++){
            if(i%m ==0 and j+1<m) {
                j++;
                cout<<j<<endl;
            }
            ans[j][i%n]=original[i];
        }
        return ans;
    }
};