#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ranges::sort(a);

	bool add = true;
	int idx = (n - 1) / 2;
	for (int i = 0; i < n; i++) {
		cout << a[idx] << " \n"[i == n - 1];

		if (add) {
			idx += i + 1;
			add = false;
		} else {
			idx -= i + 1;
			add = true;
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