class Solution {
public:
    vector<int> isPrime;
    vector<int> prime;

    void sieve(int n) {
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
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int n = ranges::max(nums);
        sieve(n);
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime[nums[i]]) {
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }
        return mx - mn;
    }
};