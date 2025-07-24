#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 a, b, k;
	cin >> a >> b >> k;

	i64 g = gcd(a, b);
	if (a / g <= k && b / g <= k) {
		cout << 1 << "\n";
	} else {
		cout << 2 << "\n";
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