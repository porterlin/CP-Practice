class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<array<int, 3>>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2], e[3]});
        }
        vector<long long> dis(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dis[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();
            if (t > dis[u]) {
                continue;
            }
            for (auto& [v, start, end] : graph[u]) {
                if (t > end) {
                    continue;
                }
                int newt = max(t, (long long)start) + 1;
                if (newt < dis[v]) {
                    dis[v] = newt;
                    pq.push({newt, v});
                }
            }
        }
        return dis[n - 1] != LLONG_MAX ? dis[n - 1] : -1;
    }
};