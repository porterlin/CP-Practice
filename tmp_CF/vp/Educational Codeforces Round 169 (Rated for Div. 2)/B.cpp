#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int l, r, L, R;
	cin >> l >> r >> L >> R;
	vector<int> a(102);

	a[l]++;
	a[r + 1]--;
	a[L]++;
	a[R + 1]--;
	int ans = 0, sum = 0;
	for (int i = 0; i < 102; i++) {
		sum += a[i];
		if (sum >= 2)
			ans++;
	}

	if (l == L && r == R)
		ans--;
	else if (l == L || r == R)
		;
	else
		ans++;
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