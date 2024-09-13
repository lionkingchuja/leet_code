class Solution {
public:
    int binary_search(vector<vector<int>>& matrix,int target){
        int j=matrix[0].size()-1;
        int lo=0;int hi=matrix.size()-1;
        while(lo <= hi){
            int mid=(lo+hi)/2;
            if(target >=matrix[mid][0] and target <=matrix[mid][j]) return mid; 
            else if(target > matrix[mid][j]) lo++;
            else hi--;
        }
        return -1;
    }
    bool search(vector<int>matrix,int target){
        int lo=0;int hi=matrix.size()-1;
        while(lo <= hi){
            int mid=(lo+hi)/2;
            if(target == matrix[mid]) return true;
            else if(target > matrix[mid]) lo++;
            else hi--;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if(matrix[0][0] ==target) return true;
        int r=-1;
        if(matrix.size()==1){
            r=0;
        }
        else r=binary_search(matrix,target);

        cout<<r<<endl;
        vector<int>v;
        for(int i=0;i<matrix.size();i++){
            if(i==r){
                for(int j=0;j<matrix[0].size();j++){
                    v.push_back(matrix[i][j]);
                }
            }
        }
        for(auto i:v) cout<<i<<" ";
        return search(v,target);
    }
};