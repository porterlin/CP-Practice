class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> pal_memo(n, vector<int>(n, -1));
        auto isPalindrome = [&](this auto&& isPalindrome, int i, int j) -> int {
            if (i >= j)
                return 1;
            if (pal_memo[i][j] != -1)
                return pal_memo[i][j];
            
            if (s[i] == s[j])
                return pal_memo[i][j] = isPalindrome(i + 1, j - 1);
            return pal_memo[i][j] = 0;
        };

        vector<int> dfs_memo(n, -1);
        auto dfs = [&](this auto&& dfs, int r) -> int {
            if (isPalindrome(0, r))
                return 0;
            if (dfs_memo[r] != -1)
                return dfs_memo[r];

            int res = 1e9;
            for (int i = 1; i <= r; i++) {
                if (isPalindrome(i, r)) {
                    res = min(res, dfs(i - 1) + 1);
                }
            }
            return dfs_memo[r] = res;
        };
        return dfs(n - 1);
    }
};