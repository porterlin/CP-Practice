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

	if (ranges::is_sorted(a)) {
		cout << 0 << "\n";
		return;
	}

	auto b = a;
	ranges::sort(b);

	int s = 0, t = n - 1;
	for (int i = 0; i < n; i++) {
		s = i;
		if (a[i] != b[i])
			break;
	}
	for (int i = n - 1; i >= 0; i--) {
		t = i;
		if (a[i] != b[i])
			break;
	}

	int cnt = 1;
	for (int i = s; i <= t; i++) {
		if (a[i] == b[i] && i < n - 1 && a[i + 1] != b[i + 1]) {
			cnt++;
		}
	}
	cout << (cnt > 2 ? 2 : cnt) << "\n";
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