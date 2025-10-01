class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int i = n; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                dp[i][j] = 1e9;
                for (int x = i; x <= j; x++) {
                    dp[i][j] = min(dp[i][j], max(dp[i][x - 1], dp[x + 1][j]) + x);
                }
            }
        }
        return dp[1][n];
    }
};