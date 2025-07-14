#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class DSU {
public:
	vector<int> parent;
	vector<int> size;

	DSU(int n): parent(n), size(n, 1) {
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
		size[y] += size[x];
		return true;
	}

	int get_size(int x) {
		return size[find(x)];
	}
};

void solve() {
	int n, m, p, q, x, y;
	cin >> n >> m >> p >> q;

	DSU dsu(n + m + 2);
	for (int i = 0; i < p + q; i++) {
		cin >> x >> y;
		if (i >= p) {
			x = abs(x) + n;
			y = abs(y) + n;
		}
		dsu.merge(x, y);
	}

	cout << min(dsu.get_size(1), dsu.get_size(n + 1)) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}