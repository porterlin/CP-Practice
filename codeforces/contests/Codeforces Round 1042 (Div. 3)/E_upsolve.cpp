#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	if (a[n - 1] != b[n - 1]) {
		cout << "NO\n";
		return;
	}

	for (int i = 0; i < n - 1; i++) {
		if (a[i] != b[i] && (a[i] ^ a[i + 1]) == b[i]) {
			a[i] ^= a[i + 1];
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		if (a[i] != b[i] && (a[i] ^ a[i + 1]) == b[i]) {
			a[i] ^= a[i + 1];
		}
	}

	cout << (a == b ? "YES\n" : "NO\n");
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