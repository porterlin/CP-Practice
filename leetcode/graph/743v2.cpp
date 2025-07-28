class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& t : times) {
            graph[t[0] - 1].push_back({t[1] - 1, t[2]});
        }

        vector<long long> dis(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dis[k - 1] = 0;
        pq.push({0, k - 1});
        while (!pq.empty()) {
            auto [dis_u, u] = pq.top();
            pq.pop();

            if (dis_u > dis[u]) {
                continue;
            }

            for (auto& [v, w] : graph[u]) {
                if (dis_u + w < dis[v]) {
                    dis[v] = dis_u + w;
                    pq.push({dis[v], v});
                }
            }
        }

        long long mx = ranges::max(dis);
        return mx == LLONG_MAX ? -1 : mx;
    }
};