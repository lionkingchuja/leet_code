class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26, vector<long long>(26, LLONG_MAX));

        // Initialize the diagonal to 0
        for (int i = 0; i < 26; ++i) {
            adj[i][i] = 0;
        }

        // Fill the adjacency matrix with given edges
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u][v] = min(adj[u][v], (long long)cost[i]);
        }
        // Floyd-Warshall algorithm
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (adj[i][k] != LLONG_MAX && adj[k][j] != LLONG_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }

        // Calculate the minimum cost to convert the source to the target
        long long totalCost = 0;
        for (int i = 0; i < source.size(); ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (adj[u][v] == LLONG_MAX) {
                return -1; // Not possible to convert
            }
            totalCost += adj[u][v];
        }

        return totalCost;
    }
};
