class Solution {
public:
    void solve(vector<int>v,int index,int k,int &ans){
        if(v.size()==1){
            ans=v[0];
            return;
        }
        index =(index+k) % v.size();
        v.erase(v.begin()+index);
        solve(v,index,k,ans);
    }
    int findTheWinner(int n, int k) {
        vector<int>v(n);
        for(int i=0;i<n;i++) v[i]=i+1;
        int index=0;
        k=k-1;
        int ans=-1;
        solve(v,index,k,ans);
        return ans;
    }
};