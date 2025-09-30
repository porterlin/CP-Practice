class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i == j)
                return 1;
            if (i > j)
                return 0;
            if (memo[i][j] != -1)
                return memo[i][j];
            
            if (s[i] == s[j])
                return memo[i][j] = dfs(i + 1, j - 1) + 2;
            return memo[i][j] = max(dfs(i + 1, j), dfs(i, j - 1));
        };
        return dfs(0, n - 1);
    }
};