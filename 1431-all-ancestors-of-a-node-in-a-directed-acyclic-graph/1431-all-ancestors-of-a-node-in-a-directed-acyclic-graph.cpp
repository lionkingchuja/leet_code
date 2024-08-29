class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i< edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>>ans(n);

        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            queue<int>q;
            q.push(i);
            vis[0]=true;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(auto it:adj[curr]){
                    if(ans[it].size()==0||ans[it].back()!=i){
                        ans[it].push_back(i);
                        q.push(it);
                    }
                }
            }
            cout<<"----"<<endl;
        }
        
        return ans;
    }
};