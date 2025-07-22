#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, x, y;
	cin >> n >> x >> y;

	i64 a = lcm(x, y);
	x = n / x - n / a;
	y = n / y - n / a;

	i64 sum1 = (n + n - x + 1) * x / 2;
	i64 sum2 = (y + 1) * y / 2;
	cout << sum1 - sum2 << "\n";
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