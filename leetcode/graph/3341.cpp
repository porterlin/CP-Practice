class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        dis[0][0] = 0;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [d, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1) {
                return d;
            }
            if (d > dis[i][j]) {
                continue;
            }

            for (auto& [dx, dy] : dxy) {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int new_dis = max(d, moveTime[x][y]) + 1;
                    if (new_dis < dis[x][y]) {
                        dis[x][y] = new_dis;
                        pq.push({new_dis, x, y});
                    }
                }
            }
        }
        return -1;
    }
};