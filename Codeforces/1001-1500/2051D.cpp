#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, x, y;
	cin >> n >> x >> y;
	vector<i64> a(n);
	for (i64 i = 0; i < n; i++) {
		cin >> a[i];
	}

	ranges::sort(a);

	i64 ans = 0;
	i64 sum = accumulate(a.begin(), a.end(), 0LL);
	x = sum - x;
	y = sum - y;
	for (i64 i = 0; i < n; i++) {
		i64 r = ranges::upper_bound(a, x - a[i]) - a.begin();
		i64 l = ranges::lower_bound(a, y - a[i]) - a.begin();
		ans += r - l;
		if (i >= l && i < r)
			ans--;
	}
	ans /= 2;
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