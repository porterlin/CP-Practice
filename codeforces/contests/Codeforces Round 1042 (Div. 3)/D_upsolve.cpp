#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (n == 2) {
		cout << 0 << "\n";
		return;
	}

	int leaf = 0;
	for (int i = 0; i < n; i++) {
		if (g[i].size() == 1) {
			leaf++;
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		int cur = leaf;
		for (auto& next : g[i]) {
			if (g[next].size() == 1) {
				cur--;
			}
		}
		ans = min(ans, cur);
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