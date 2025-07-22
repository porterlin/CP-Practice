#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 a, b, x, y;
	cin >> a >> b >> x >> y;

	if (a > b) {
		if (a - b > 1 || a % 2 == 0)
			cout << -1 << "\n";
		else
			cout << (a - b) * y << "\n";
		return;
	}
	if (a == b) {
		cout << 0 << "\n";
		return;
	}

	if (x <= y) {
		cout << (b - a) * x << "\n";
	} else {
		i64 add = 0, xo = 0;
		for (int i = a; i < b; i++) {
			if (i % 2 == 0)
				xo++;
			else
				add++;
		}
		cout << add * x + xo * y << "\n";
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