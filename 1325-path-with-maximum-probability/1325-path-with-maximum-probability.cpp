class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> vp[n];
        for(int i = 0; i < edges.size(); i++) {
            vp[edges[i][0]].push_back({edges[i][1], succProb[i]});
            vp[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> dis(n, 0.0);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        dis[start_node] = 1.0;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int node = curr.second;
            double curr_prob = curr.first;
            // if (node == end_node) {
            //     return curr_prob;
            // }
            // if (curr_prob < dis[node]) continue;
            
            for (auto& neighbor : vp[node]) {
                int next_node = neighbor.first;
                double next_prob = neighbor.second;
                
                if (dis[next_node] < curr_prob * next_prob) {
                    dis[next_node] = curr_prob * next_prob;
                    pq.push({dis[next_node], next_node});
                }
            }
        }
        
        return dis[end_node];
    }
};
