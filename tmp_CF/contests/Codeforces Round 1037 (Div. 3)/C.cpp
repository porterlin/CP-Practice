#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, k;
	cin >> n >> k;
	vector<i64> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	k--;
	i64 start = h[k];
	ranges::sort(h);
	start = ranges::find(h, start) - h.begin();
	i64 water = 1;
	for (int i = start; i < h.size() - 1; i++) {
		if (h[i] < water + h[i + 1] - h[i] - 1) {
			cout << "NO\n";
			return;
		}
		water += h[i + 1] - h[i];
	}
	cout << "YES\n";
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