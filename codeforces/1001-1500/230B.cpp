#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 mx = 1e6;

vector<i64> is_prime;
vector<i64> primes;
unordered_set<i64> primes_square;

void sieve(i64 n) {
	is_prime.assign(n + 1, 1);
	primes.clear();
	primes_square.clear();
	is_prime[0] = is_prime[1] = 0;

	for (i64 i = 2; i <= n; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			primes_square.insert(i * i);
		}

		for (i64 p : primes) {
			if (i * p > n)
				break;
			is_prime[i * p] = 0;
			if (i % p == 0)
				break;
		}
	}
}

void solve() {
	i64 x;
	cin >> x;
	cout << (primes_square.contains(x) ? "YES\n" : "NO\n");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve(mx);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}