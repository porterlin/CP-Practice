#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	vector<int> a(n);
	a[0] = d[0];
	for (int i = 1; i < n; i++) {
		if (a[i - 1] - d[i] >= 0 && d[i] != 0) {
			cout << -1 << "\n";
			return;
		}
		a[i] = d[i] + a[i - 1];
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
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