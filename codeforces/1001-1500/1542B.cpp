#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;

	for (i64 x = 1; x <= n; x *= a) {
		if ((n - x) % b == 0) {
			cout << "Yes\n";
			return;
		}
		if (a == 1)
			break;
	}
	cout << "No\n";
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