#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, odd = 0, even = 0;
	cin >> n;
	vector<i64> a(n);
	for (i64 i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2)
			odd++;
		else
			even++;
	}

	if (odd > 0 && even > 0) {
		cout << 2 << "\n";
	} else {
		i64 k = 4;
		while (true) {
			for (i64 i = 0; i < n; i++) {
				if (a[i] % k != a[0] % k) {
					cout << k << "\n";
					return;
				}
			}
			k *= 2;
		}
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