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

	if (n <= 3) {
		cout << -1 << "\n";
		return;
	}

	int mn = 1, mx = n;
	int l = 0, r = n - 1;
	while (l <= r) {
		if (a[l] != mx && a[l] != mn && a[r] != mx && a[r] != mn) {
			cout << l + 1 << " " << r + 1 << "\n";
			return;
		}

		if (a[l] == mx) {
			mx--;
			l++;
		}
		if (a[l] == mn) {
			mn++;
			l++;
		}
		if (a[r] == mx) {
			mx--;
			r--;
		}
		if (a[r] == mn) {
			mn++;
			r--;
		}
	}
	cout << -1 << "\n";
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