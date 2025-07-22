#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, k;
	cin >> n >> k;
	vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ranges::sort(a);

	i64 alice = 0, bob = 0;
	for (int i = n - 1; i >= 0; i -= 2) {
		alice += a[i];
		if (i - 1 < 0)
			break;
		bob += a[i - 1];
		if (k > 0) {
			if (bob + k >= alice) {
				k -= alice - bob;
				bob = alice;
			} else {
				bob += k;
				k = 0;
			}
		}
	}
	cout << alice - bob << "\n";
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