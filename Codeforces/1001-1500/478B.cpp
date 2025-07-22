#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, m;
	cin >> n >> m;

	i64 mn = ceil(n / (double)m);
	if (n % m == 0)
		mn = mn * (mn - 1) / 2 * m;
	else {
		i64 cntA = n % m;
		i64 cntB = m - cntA;

		mn = mn * (mn - 1) / 2 * cntA + (mn - 1) * (mn - 2) / 2 * cntB;
	}

	i64 mx = n - (m - 1);
	mx = mx * (mx - 1) / 2;
	cout << mn << " " << mx << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}