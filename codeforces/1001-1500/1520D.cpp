#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n;
	cin >> n;
	vector<i64> a(n);
	for (i64 i = 0; i < n; i++) {
		cin >> a[i];
	}

	i64 ans = 0;
	unordered_map<i64, i64> mp;
	for (i64 i = 0; i < n; i++) {
		if (mp.contains(a[i] - i)) {
			ans += mp[a[i] - i];
		}
		mp[a[i] - i]++;
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