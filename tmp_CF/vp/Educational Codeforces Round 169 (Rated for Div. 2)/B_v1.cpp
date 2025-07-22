#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int l, r, L, R;
	cin >> l >> r >> L >> R;

	int ans = 0;
	if (r < L || R < l) {
		cout << 1 << "\n";
	} else {
		cout << min(r, R) - max(l, L) + (r != R) + (l != L) << "\n";
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