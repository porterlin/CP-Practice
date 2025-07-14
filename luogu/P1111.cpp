#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class DSU {
public:
	vector<int> parent;
	int cc;

	DSU(int n): parent(n), cc(n) {
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
		cc--;
		return true;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> roads(m);
	for (int i = 0; i < m; i++) {
		cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
	}

	sort(roads.begin(), roads.end(), [](auto & a, auto & b) {
		return a[2] < b[2];
	});

	DSU dsu(n);
	for (auto& r : roads) {
		dsu.merge(r[0] - 1, r[1] - 1);
		if (dsu.cc == 1) {
			cout << r[2] << "\n";
			return;
		}
	}
	cout << -1 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}