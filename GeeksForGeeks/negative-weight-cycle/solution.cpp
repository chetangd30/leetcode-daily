class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<long long> dist(V, 0);

        // Relax all edges V - 1 times
        for (int i = 1; i <= V - 1; i++) {
            bool changed = false;

            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }

            if (!changed)
                return false;
        }

        // If relaxation is still possible, a negative cycle exists
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] + w < dist[v])
                return true;
        }

        return false;
    }
};