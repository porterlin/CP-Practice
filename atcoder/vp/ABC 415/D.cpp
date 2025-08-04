#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, m, a, b;
	cin >> n >> m;
	vector<array<i64, 2>> d(m);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		d[i] = {a - b, a};
	}
	ranges::sort(d);
	i64 ans = 0;
	for (int i = 0; i < m; i++) {
		if (n < d[i][1]) {
			continue;
		}
		i64 cnt = (n - d[i][1]) / d[i][0] + 1;
		ans += cnt;
		n -= cnt * d[i][0];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}