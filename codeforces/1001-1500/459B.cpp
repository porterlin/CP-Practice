#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	i64 mn = LLONG_MAX, mx = LLONG_MIN;
	vector<i64> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		mn = min(mn, b[i]);
		mx = max(mx, b[i]);
	}

	i64 t = mx - mn, ans = 0;
	unordered_map<i64, i64> mp;
	for (int i = 0; i < n; i++) {
		if (mp.contains(t + b[i])) {
			ans += mp[t + b[i]];
		}
		if (t != 0 && mp.contains(b[i] - t)) {
			ans += mp[b[i] - t];
		}
		mp[b[i]]++;
	}

	cout << t << " " << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}