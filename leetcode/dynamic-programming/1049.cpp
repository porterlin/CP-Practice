class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1);
        for (auto& x : stones) {
            for (int i = target; i >= x; i--) {
                dp[i] = max(dp[i], dp[i - x] + x);
            }
        }
        return abs(dp[target] - (sum - dp[target]));
    }
};