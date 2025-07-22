#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n;
	cin >> n;
	vector<i64> a(n + 1, 1e9);
	for (i64 i = 0; i < n; i++) {
		cin >> a[i];
	}

	ranges::sort(a);

	i64 ans = 0, cnt = 0, idx = 0;
	for (i64 i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) {
			cnt++;
		} else {
			cnt++;
			if (cnt >= 2) {
				ans += cnt * (cnt - 1) / 2 * idx;
			}
			if (cnt >= 3) {
				ans += cnt * (cnt - 1) * (cnt - 2) / 6;
			}
			idx = i + 1;
			cnt = 0;
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