#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int a;
	cin >> a;

	int n = 3;
	while (true) {
		int sum = 180 * (n - 2);
		if (a * n == sum) {
			cout << "YES\n";
			return;
		}
		if (a * n < sum) {
			cout << "NO\n";
			return;
		}
		n++;
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