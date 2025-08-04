class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        const int INF = 1e9;
        vector<vector<int>> g(n, vector<int>(n, INF));
        for (auto& r : roads) {
            int u = r[0], v = r[1], w = r[2];
            g[u][v] = min(g[u][v], w);
            g[v][u] = min(g[v][u], w);
        }
        for (int i = 0; i < n; i++) {
            g[i][i] = 0;
        }
        int ans = 0;
        vector<int> c(n);
        for (int num = 0; num < (1 << n); num++) {
            int a = num, idx = 0;
            while (a > 0) {
                c[idx++] = a & 1;
                a >>= 1;
            }
            auto f = g;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (c[i] == 0 || c[j] == 0) {
                        f[i][j] = INF;
                    }
                }
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                    }
                }
            }
            bool ok = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((f[i][j] != INF && f[i][j] > maxDistance) || (c[i] == 1 && c[j] == 1 && f[i][j] == INF)) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                ans++;
            }
        }
        return ans;
    }
};