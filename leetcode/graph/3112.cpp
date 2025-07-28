class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<int> ans(n, -1);
        vector<long long> dis(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dis[0] = ans[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u]) {
                continue;
            }
            for (auto& [v, w] : graph[u]) {
                if (d + w < dis[v] && d + w < disappear[v]) {
                    dis[v] = ans[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return ans;
    }
};