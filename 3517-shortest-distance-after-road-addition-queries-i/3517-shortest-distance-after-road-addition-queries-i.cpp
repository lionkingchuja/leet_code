class Solution {
public:
    int solve(int start,vector<int>adj[],int n){
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(start);
        visited[start]=true;

        int count=0;
        while(!q.empty()){
            int len=q.size();
            count++;
            while(len--){
                int curr=q.front();
                q.pop();
                for(auto i:adj[curr]){
                    if(visited[i]==false){
                        if(i==n-1) return count;
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans;

        for(int i=0;i<queries.size();i++){
            adj[queries[i][0]].push_back(queries[i][1]);
            int x=solve(0,adj,n);
            ans.push_back(x);
        }
        
        return ans;
    }
};