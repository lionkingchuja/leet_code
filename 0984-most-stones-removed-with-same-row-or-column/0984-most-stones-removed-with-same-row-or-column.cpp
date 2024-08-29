class Solution {
public:
    void solve(int i, vector<int> adj[], vector<int>& vis) {
    if (vis[i] == true) return;
    vis[i] = true;
    for (auto it : adj[i]) {
        if (vis[it] == false) solve(it, adj, vis);
    }
}

int removeStones(vector<vector<int>>& stones) {
    vector<int> adj[1001];
    for (int i = 0; i < stones.size(); i++) {
        for (int j = i + 1; j < stones.size(); j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> vis(1001, false);
    int cnt_component = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (vis[i] == false) {
            solve(i, adj, vis);
            cnt_component++;
        }
    }
    return stones.size() - cnt_component;
    }
};