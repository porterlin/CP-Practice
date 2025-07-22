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

	string s(n, '0');
	s[0] = '1';
	s[n - 1] = '1';
	vector<int> suf(n);
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = max(suf[i + 1], a[i + 1]);
	}

	int mn = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < mn || a[i] > suf[i])
			s[i] = '1';
		mn = min(mn, a[i]);
	}
	cout << s << "\n";
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