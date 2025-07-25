vector<int> isPrime;
vector<int> prime;

int init = []() {
    int n = 4e6;
    isPrime.assign(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    prime.clear();

    for (int i = 0; i <= n; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
            
        for (auto& p : prime) {
            if (i * p > n)
                break;
            isPrime[i * p] = 0;
            if (i % p == 0)
                break;
        }
    }
    return 0;
} ();

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), ans = 0;
        for (int j = 0, i = 0; j < n; j++, i++) {
            if (isPrime[nums[i][j]]) {
                ans = max(ans, nums[i][j]);
            }
        }
        for (int j = 0, i = n - 1; j < n; j++, i--) {
            if (isPrime[nums[i][j]]) {
                ans = max(ans, nums[i][j]);
            }
        }
        return ans;
    }
};