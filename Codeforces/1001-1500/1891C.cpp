#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for (i64 i = 0; i < n; i++) {
		cin >> a[i];
	}

	ranges::sort(a);

	i64 sum = accumulate(a.begin(), a.end(), 0LL);
	i64 s = sum / 2;
	i64 ans = sum - s;
	for (int i = n - 1; i >= 0; i--) {
		if (s > 0) {
			s -= a[i];
			ans++;
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