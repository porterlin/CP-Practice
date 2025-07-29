class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<int>> dis(n, vector<int>(m)), vis(n, vector<int>(m));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        dis[0][0] = 0;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [d, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1) {
                return d;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = 1;
            for (auto& [dx, dy] : dxy) {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int new_d = max(d, abs(heights[x][y] - heights[i][j]));
                    dis[i][j] = new_d;
                    pq.push({new_d, x, y});
                }
            }
        }
        return -1;
    }
};