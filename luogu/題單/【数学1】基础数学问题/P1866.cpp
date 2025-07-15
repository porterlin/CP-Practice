#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int MOD = 1e9 + 7;

void solve() {
	i64 n;
	cin >> n;
	vector<i64> a(n);
	for (i64 i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	i64 ans = 1;
	for (i64 i = 0; i < n; i++) {
		if (a[i] - i > 0) {
			ans = (ans * (a[i] - i)) % MOD;
		} else {
			ans = 0;
			break;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}