#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int k, l, m, n, d, ans = 0;
	cin >> k >> l >> m >> n >> d;

	for (int i = 0; i < d; i++) {
		if ((i + 1) % k == 0 || (i + 1) % l == 0 || (i + 1) % m == 0 || (i + 1) % n == 0)
			ans++;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}