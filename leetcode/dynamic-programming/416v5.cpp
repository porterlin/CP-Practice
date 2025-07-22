class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        
        sum /= 2;

        int n = nums.size();
        vector<int> dp(sum + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = sum; c >= nums[i]; c--) {
                dp[c] = dp[c] || dp[c - nums[i]];
            }
        }
        return dp[sum];
    }
};