class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        int i=0;
        int j=0;
        while(i<n and j<m){
            int temp=min(rowSum[i],colSum[j]);
            ans[i][j]=temp;
            cout<<i<<" "<<j<<endl;
            if(rowSum[i] < colSum[j]) {
                colSum[j] -=temp;
                i++;
            }
            else if(rowSum[i] > colSum[j]) {
                rowSum[i] -=temp;
                j++;
            }
            else {
                i++;
                j++;
            }
        }
        return ans;
    }
};