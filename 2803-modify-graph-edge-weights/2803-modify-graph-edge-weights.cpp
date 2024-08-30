class Solution {
public:
    const int INF = INT_MAX;
    vector<int> dist;  // Declaring the vector
    vector<bool> vis;  // Declaring the vector

    Solution() : dist(100000, INF), vis(100000, false) {}//Initializing constructor

    void dijkshtra(int start,vector<pair<int,int>>vp[]){
        set<pair<int,int>>s;
        s.insert({0,start});
        dist[start]=0;
        while(!s.empty()){
            auto curr=*s.begin();
            int curr_node=curr.second;
            int wt=curr.first;
            s.erase(s.begin());
            if(vis[curr_node]) continue;
            vis[curr_node]=1;
            for(auto i:vp[curr_node]){
                int new_wt=i.second;
                int new_node=i.first;
                if(dist[new_node] > dist[curr_node]+new_wt){
                    dist[new_node]=dist[curr_node]+new_wt;
                    s.insert({dist[new_node],new_node});
                }
            }
        }
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<pair<int,int>>vp[n];
        for(int  i=0;i<edges.size();i++){
            if(edges[i][2]==-1) continue;
            vp[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            vp[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        dijkshtra(src,vp);

        if(dist[dest] < target) return {};

         if(dist[dest] == target) {
            for(auto& edge : edges) {
                if(edge[2] == -1) edge[2] =1000000000;
            }
            return edges;
        }
        queue<int> q;
        for(int i = 0; i < edges.size(); i++) {
            auto& edge = edges[i];
            int u = edge[0], v = edge[1], wt = edge[2];
            if(wt == -1) {
                edge[2] = 1;
                vp[u].emplace_back(v, 1);
                vp[v].emplace_back(u, 1);
                
                fill(dist.begin(), dist.end(), INF);
                dist[src] = 0;
                q.push(src);
                
                while(!q.empty()) {
                    u = q.front();
                    q.pop();
                    for(auto& pair : vp[u]) {
                        int nxt = pair.first, wt = pair.second;
                        if(dist[nxt] > dist[u] + wt) {
                            dist[nxt] = dist[u] + wt;
                            q.push(nxt);
                        }
                    }
                }
                
                if(dist[dest] <= target) {
                    edge[2] += (target - dist[dest]);
                    for(int j = i + 1; j < edges.size(); j++) {
                        if(edges[j][2] == -1) {
                            edges[j][2] = 1000000000;
                        }
                    }
                    return edges;
                }
            }
        }
        
        return {};
    }
};