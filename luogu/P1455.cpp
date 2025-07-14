#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class DSU {
public:
	vector<int> parent;
	vector<int> money;
	vector<int> val;

	DSU(int n): parent(n), money(n), val(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find(parent[x]);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		parent[x] = y;
		money[y] += money[x];
		val[y] += val[x];
		return true;
	}
};

void solve() {
	int n, m, w, c, d, u, v;
	cin >> n >> m >> w;

	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		cin >> c >> d;
		dsu.money[i] = c;
		dsu.val[i] = d;
	}

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--;
		v--;
		dsu.merge(u, v);
	}

	vector<int> dp(w + 1);
	for (int i = 0; i < n; i++) {
		if (dsu.parent[i] == i) {
			for (int cc = w; cc >= dsu.money[i]; cc--) {
				dp[cc] = max(dp[cc], dp[cc - dsu.money[i]] + dsu.val[i]);
			}
		}
	}
	cout << dp[w] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}