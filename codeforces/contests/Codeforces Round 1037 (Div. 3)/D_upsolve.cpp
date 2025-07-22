#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, k;
	cin >> n >> k;
	vector<array<i64, 3>> ar(n);
	for (i64 i = 0; i < n; i++) {
		cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
	}

	ranges::sort(ar, [](auto & a, auto & b) {
		return a[2] < b[2];
	});

	for (i64 i = 0; i < n; i++) {
		if (k >= ar[i][0] && k <= ar[i][1]) {
			k = max(k, ar[i][2]);
		}
	}
	cout << k << "\n";
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