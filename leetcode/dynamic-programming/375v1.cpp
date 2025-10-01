class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i >= j)
                return 0;
            if (memo[i][j] != -1)
                return memo[i][j];
            
            int res = 1e9;
            for (int x = i; x <= j; x++) {
                res = min(res, max(dfs(i, x - 1), dfs(x + 1, j)) + x);
            }
            return memo[i][j] = res;
        };
        return dfs(1, n);
    }
};