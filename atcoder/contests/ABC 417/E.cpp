#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	x--, y--;
	vector<set<int>> graph(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		graph[u].insert(v);
		graph[v].insert(u);
	}

	vector<int> vis(n);
	vector<int> path;
	auto dfs = [&](auto&& dfs, int node) -> bool {
		if (node == y) {
			for (int i = 0; i < path.size(); i++) {
				cout << path[i] + 1 << " ";
			}
			cout << node + 1 << "\n";
			return true;
		}
		if (vis[node]) {
			return false;
		}

		vis[node] = 1;
		path.push_back(node);
		for (auto& next : graph[node]) {
			if (!vis[next] && dfs(dfs, next)) {
				return true;
			}
		}
		path.pop_back();
		return false;
	};
	dfs(dfs, x);
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