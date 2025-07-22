#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, px, py, qx, qy, r = 0;
	cin >> n >> px >> py >> qx >> qy;
	vector<i64> a(n);
	for (i64 i = 0; i < n; i++) {
		cin >> a[i];
		r += a[i];
	}

	ranges::sort(a);
	i64 l = a[n - 1];
	for (int i = 0; i < n - 1; i++) {
		l -= a[i];
	}
	l = max(l, 0LL);

	i64 d = (px - qx) * (px - qx) + (py - qy) * (py - qy);
	if (d <= r * r && d >= l * l)
		cout << "Yes\n";
	else
		cout << "No\n";
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