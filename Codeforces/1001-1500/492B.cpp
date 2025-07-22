#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, l;
	cin >> n >> l;
	vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ranges::sort(a);
	a.erase(unique(a.begin(), a.end()), a.end());

	n = a.size();
	vector<i64> b(n + 1);
	b[0] = a[0] * 2;
	b[n] = (l - a[n - 1]) * 2;
	for (int i = 1; i < n; i++) {
		b[i] = a[i] - a[i - 1];
	}
	i64 mx = ranges::max(b);
	cout << fixed << setprecision(10) << mx / 2.0 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}