class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>v(1e5+7);
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int mi=INT_MAX;
            for(int j=0;j<m;j++){
                mi=min(matrix[i][j],mi);
            }
            v[mi]++;
        }
        for(int i=0;i<m;i++){
            int mx=INT_MIN;
            for(int j=0;j<n;j++){
                mx=max(matrix[j][i],mx);
            }
            v[mx]++;
        }

        int ans=-1;
        for(int i=0;i<v.size();i++){
            if(v[i]==2){
                ans=i;
                break;
            }
        }
        if(ans !=-1) return vector<int>({ans});
        else return vector<int>({});
    }
};