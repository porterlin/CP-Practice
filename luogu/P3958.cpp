#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class DSU {
public:
	vector<i64> parent;
	vector<i64> size;
	i64 cc;

	DSU(i64 n): parent(n), size(n, 1), cc(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	i64 find(i64 x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find(parent[x]);
	}

	bool is_same(i64 x, i64 y) {
		return find(x) == find(y);
	}

	bool merge(i64 x, i64 y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		parent[x] = y;
		size[y] += size[x];
		size[x] = size[y];
		cc--;
		return true;
	}
};

i64 calDist(array<i64, 3> a, array<i64, 3> b) {
	return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2]);
}

void solve() {
	i64 n, h, r, x, y, z;
	cin >> n >> h >> r;
	vector<array<i64, 3>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		a[i] = {x, y, z};
	}

	DSU dsu(n);
	vector<i64> start;
	vector<i64> end;
	for (int i = 0; i < n; i++) {
		if (a[i][2] - r <= 0) {
			start.push_back(i);
		}
		if (a[i][2] + r >= h) {
			end.push_back(i);
		}
		for (int j = i + 1; j < n; j++) {
			if (calDist(a[i], a[j]) <= 4 * r * r) {
				dsu.merge(i, j);
			}
		}
	}

	for (auto& s : start) {
		for (auto& t : end) {
			if (dsu.is_same(s, t)) {
				cout << "Yes\n";
				return;
			}
		}
	}
	cout << "No\n";
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