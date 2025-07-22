#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, k;
	cin >> n >> k;
	if (n % 2 == 0) {
		if ((n - 2 * (k - 1)) > 0 && (n - 2 * (k - 1)) % 2 == 0) {
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++) {
				cout << 2 << " ";
			}
			cout << n - 2 * (k - 1) << "\n";
		} else if ((n - (k - 1)) > 0 && (n - (k - 1)) % 2) {
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++) {
				cout << 1 << " ";
			}
			cout << n - (k - 1) << "\n";
		} else {
			cout << "NO\n";
		}
	} else {
		if (k % 2 == 1) {
			if ((n - (k - 1)) > 0 && (n - (k - 1)) % 2) {
				cout << "YES\n";
				for (int i = 0; i < k - 1; i++) {
					cout << 1 << " ";
				}
				cout << n - (k - 1) << "\n";
			} else {
				cout << "NO\n";
			}
		} else {
			cout << "NO\n";
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