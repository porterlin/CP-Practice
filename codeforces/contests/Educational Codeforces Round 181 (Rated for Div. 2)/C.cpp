#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 l, r;
	cin >> l >> r;

	l--;
	i64 rr = r - (r / 2) - (r / 3) - (r / 5) - (r / 7) + (r / 6) + (r / 10) + (r / 14) + (r / 15) + (r / 21) + (r / 35) - (r / 30) - (r / 42) - (r / 70) - (r / 105) + (r / 210);
	i64 ll = l - (l / 2) - (l / 3) - (l / 5) - (l / 7) + (l / 6) + (l / 10) + (l / 14) + (l / 15) + (l / 21) + (l / 35) - (l / 30) - (l / 42) - (l / 70) - (l / 105) + (l / 210);
	cout << rr - ll << "\n";
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