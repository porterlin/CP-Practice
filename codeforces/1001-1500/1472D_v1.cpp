#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ranges::sort(a, greater<>());

	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == a[i] % 2) {
			if (i % 2 == 0)
				ans += a[i];
			else
				ans -= a[i];
		}
	}

	if (ans > 0) {
		cout << "Alice\n";
	} else if (ans < 0) {
		cout << "Bob\n";
	} else {
		cout << "Tie\n";
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