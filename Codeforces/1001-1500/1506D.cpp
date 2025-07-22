#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, a, mx = INT_MIN;
	cin >> n;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mp[a]++;
		mx = max(mx, mp[a]);
	}

	if (mx > n - mx) {
		cout << mx - (n - mx) << "\n";
	} else {
		cout << (n & 1) << "\n";
	}
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