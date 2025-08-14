#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	if (n == 2) {
		cout << -1 << " " << 2 << "\n";
	} else {
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				if (n % 2 == 0) {
					cout << 2 << "\n";
				} else {
					cout << -1 << "\n";
				}
				break;
			}
			if (i % 2 == 0) {
				cout << -1 << " ";
			} else {
				cout << 3 << " ";
			}
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