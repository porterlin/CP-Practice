class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i + 1 == j)
                return 0;
            if (memo[i][j] != -1)
                return memo[i][j];
            
            int res = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                res = min(res, dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]);
            }
            return memo[i][j] = res;
        };
        return dfs(0, n - 1);
    }
};