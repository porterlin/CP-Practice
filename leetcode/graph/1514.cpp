class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back({v, succProb[i]});
            graph[v].push_back({u, succProb[i]});
        }
        vector<double> dis(n);
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<>> pq;
        dis[start_node] = 1;
        pq.push({1, start_node});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (u == end_node) {
                return d;
            }
            if (d < dis[u]) {
                continue;
            }
            for (auto& [v, p] : graph[u]) {
                if (d * p > dis[v]) {
                    dis[v] = d * p;
                    pq.push({dis[v], v});
                }
            }
        }
        return 0;
    }
};