class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector memo(n, vector(k + 1, vector<int>(2, -1)));

        auto dfs = [&](this auto&& dfs, int i, int j, int hold) -> int {
            if (j < 0) {
                return INT_MIN;
            }
            if (i < 0) {
                return hold == 0 ? 0 : INT_MIN;
            }
            if (memo[i][j][hold] != -1) {
                return memo[i][j][hold];
            }

            if (hold) {
                return memo[i][j][hold] = max(dfs(i - 1, j, 1), dfs(i - 1, j, 0) - prices[i]);
            }
            return memo[i][j][hold] = max(dfs(i - 1, j, 0), dfs(i - 1, j - 1, 1) + prices[i]);
        };

        return dfs(n - 1, k, 0);
    }
};