class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        auto dfs = [&](this auto&& dfs, int i, int j, int target) -> int {
            if (i >= j)
                return 0;
            if (memo[i][j] != -1)
                return memo[i][j];
            
            int res = 0;
            if (nums[i] + nums[i + 1] == target) {
                res = max(res, dfs(i + 2, j, target) + 1);
            }
            if (nums[j] + nums[j - 1] == target) {
                res = max(res, dfs(i, j - 2, target) + 1);
            }
            if (nums[i] + nums[j] == target) {
                res = max(res, dfs(i + 1, j - 1, target) + 1);
            }
            return memo[i][j] = res;
        };
        return max({dfs(2, n - 1, nums[0] + nums[1]), dfs(0, n - 3, nums[n - 1] + nums[n - 2]), dfs(1, n - 2, nums[0] + nums[n - 1])}) + 1;
    }
};