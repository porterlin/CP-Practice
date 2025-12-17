class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector dp(n + 1, vector(k + 2, vector<int>(2, INT_MIN)));
        for (int j = 1; j < k + 2; j++) {
            dp[0][j][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k + 1; j++) {
                dp[i + 1][j + 1][0] = max(dp[i][j + 1][0], dp[i][j][1] + prices[i]);
                dp[i + 1][j + 1][1] = max(dp[i][j + 1][1], dp[i][j + 1][0] - prices[i]);
            }
        }
        return dp[n][k + 1][0];
    }
};