#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, k;
	cin >> n >> k;

	if (n <= k) {
		cout << 1 << "\n";
		return;
	}

	i64 ans = INT_MAX;
	for (i64 i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i <= k) {
				ans = min(ans, n / i);
			}
			if (n / i <= k) {
				ans = min(ans, i);
			}
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}