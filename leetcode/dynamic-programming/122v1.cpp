class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));

        auto dfs = [&](this auto&& dfs, int i, int hold) -> int {
            if (i < 0) {
                return hold == 0 ? 0 : INT_MIN;
            }
            if (memo[i][hold] != -1) {
                return memo[i][hold];
            }

            if (hold) {
                return memo[i][hold] = max(dfs(i - 1, 1), dfs(i - 1, 0) - prices[i]);
            }
            return memo[i][hold] = max(dfs(i - 1, 0), dfs(i - 1, 1) + prices[i]);
        };

        return dfs(n - 1, 0);
    }
};