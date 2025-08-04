#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, t;
	string s;
	cin >> n >> s;

	vector<int> dp(1 << n);
	dp[0] = 1;
	for (int x = 0; x < (1 << n); x++) {
		if (!dp[x]) {
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (x ^ (1 << i)) {
				int mask = x | (1 << i);
				if (s[mask - 1] == '0') {
					dp[mask] = 1;
				}
			}
		}
	}

	cout << (dp[(1 << n) - 1] ? "Yes" : "No") << "\n";
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