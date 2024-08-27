class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<pair<int,double>>adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
    }
    vector<double>dist(n,0.0);
    queue<pair<int,double>>q;
    q.push({start_node,1.0});
    dist[start_node]=1.0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        for(auto v:adj[it.first]){
            if(dist[v.first] <it.second *v.second){
                dist[v.first]= it.second* v.second;
                q.push({v.first,dist[v.first]});
            }
        }
    }
    return dist[end_node];
    }
};