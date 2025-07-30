#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr long long INF = 1e18;

void solve() {
	i64 n, m, k, t, q;
	cin >> n >> m;
	vector<vector<i64>> f(n + 1, vector<i64>(n + 1, INF));
	for (int i = 0; i < m; i++) {
		i64 a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		f[a][b] = min(f[a][b], c * 2);
		f[b][a] = min(f[b][a], c * 2);
	}
	cin >> k >> t;
	for (int i = 0; i < k; i++) {
		i64 ap;
		cin >> ap;
		ap--;
		f[ap][n] = min(f[ap][n], t);
		f[n][ap] = min(f[n][ap], t);
	}
	for (int i = 0; i <= n; i++) {
		f[i][i] = 0;
	}
	for (int k = 0; k <= n; k++) {
		for (int i = 0; i <= n; i++) {
			if (f[i][k] == INF) {
				continue;
			}
			for (int j = 0; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	auto update = [&](i64 u, i64 v, i64 w) {
		f[u][v] = min(f[u][v], w);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][u] + f[u][v] + f[v][j]);
			}
		}
	};
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			i64 x, y, tt;
			cin >> x >> y >> tt;
			x--, y--;
			update(x, y, tt * 2);
			update(y, x, tt * 2);
		} else if (type == 2) {
			i64 x;
			cin >> x;
			x--;
			update(x, n, t);
			update(n, x, t);
		} else {
			i64 hours = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (f[i][j] == INF) {
						continue;
					}
					hours += f[i][j];
				}
			}
			cout << hours / 2 << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}