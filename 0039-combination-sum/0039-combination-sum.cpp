class Solution {
public:
    void solve(int i,int target,vector<int>&c,vector<vector<int>>&ans,vector<int>&ds){
        if(i==c.size()){
            if(target ==0) ans.push_back(ds);
            return;
        }
        if(c[i] <= target){
            ds.push_back(c[i]);
            solve(i,target-c[i],c,ans,ds);
            ds.pop_back();
        }
        solve(i+1,target,c,ans,ds);
        
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,target,c,ans,ds);
        return ans;
    }
};