#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int x;
	string s;
	cin >> s >> x;

	int n = s.size();
	string ans(n, '.');
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (i + x < n)
				ans[i + x] = '0';
			if (i - x >= 0)
				ans[i - x] = '0';
		}
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			bool ok1 = false, ok2 = false;
			if (i + x < n && ans[i + x] != '0') {
				ans[i + x] = '1';
				ok1 = true;
			}
			if (i - x >= 0 && ans[i - x] != '0') {
				ans[i - x] = '1';
				ok2 = true;
			}
			if (!ok1 && !ok2) {
				cout << -1 << "\n";
				return;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == '.')
			ans[i] = '1';
	}
	cout << ans << "\n";
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