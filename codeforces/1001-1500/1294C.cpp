#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n;
	cin >> n;

	vector<i64> factors;

	for (i64 i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				factors.push_back(i);
				cnt++;
			}
		}
	}

	if (n > 1) {
		factors.push_back(n);
	}

	if (factors.size() < 3) {
		cout << "NO\n";
		return;
	}

	i64 a = factors[0], b = 1, c = 1;

	int start = 0;
	if (factors[0] == factors[1]) {
		b = factors[1] * factors[2];
		start = 3;
	} else {
		b = factors[1];
		start = 2;
	}

	for (int i = start; i < factors.size(); i++) {
		c *= factors[i];
	}

	if (c == a || c == b || c == 1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << a << " " << b << " " << c << "\n";
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