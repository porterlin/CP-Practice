vector<int> isPrime;
vector<int> prime;

int init = []() {
    int n = 32;
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
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int num = left; num <= right; num++) {
            if (isPrime[popcount((unsigned)num)])
                ans++;
        }
        return ans;
    }
};