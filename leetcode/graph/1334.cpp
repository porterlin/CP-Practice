class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> f(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            f[i][i] = 0;
        }
        for (auto& e : edges) {
            f[e[0]][e[1]] = e[2];
            f[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        int cnt = INT_MAX, ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt1 = 0;
            for (int j = 0; j < n; j++) {
                if (f[i][j] <= distanceThreshold) {
                    cnt1++;
                }
            }
            if (cnt1 <= cnt) {
                cnt = cnt1;
                ans = i;
            }
        }
        return ans;
    }
};