#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int a1, a2, b1, b2, ans = 0;
	cin >> a1 >> a2 >> b1 >> b2;
	if ((a1 > b1 && a2 > b2) || (a1 > b1 && a2 == b2) || (a2 > b2 && a1 == b1))
		ans++;
	if ((a1 > b2 && a2 > b1) || (a1 > b2 && a2 == b1) || (a2 > b1 && a1 == b2))
		ans++;
	if ((a2 > b1 && a1 > b2) || (a2 > b1 && a1 == b2) || (a1 > b2 && a2 == b1))
		ans++;
	if ((a2 > b2 && a1 > b1) || (a2 > b2 && a1 == b1) || (a1 > b1 && a2 == b2))
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