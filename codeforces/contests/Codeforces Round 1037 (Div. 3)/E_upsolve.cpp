#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n;
	cin >> n;
	vector<i64> p(n), s(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	auto check = [&]() -> bool {
		vector<i64> a(n);
		for (i64 i = 0; i < n; i++) {
			a[i] = lcm(p[i], s[i]);
		}

		i64 x = a[0];
		for (i64 i = 0; i < n; i++) {
			x = gcd(x, a[i]);
			if (x != p[i]) {
				return false;
			}
		}

		x = a[n - 1];
		for (i64 i = n - 1; i >= 0; i--) {
			x = gcd(x, a[i]);
			if (x != s[i]) {
				return false;
			}
		}

		return true;
	};

	cout << (check() ? "YES" : "NO") << "\n";
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