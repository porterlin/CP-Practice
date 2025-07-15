#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n, k, r, c;
	cin >> n >> k;

	unordered_set<i64> row;
	unordered_set<i64> col;
	while (k--) {
		cin >> r >> c;

		row.insert(r);
		col.insert(c);
	}

	r = row.size();
	c = col.size();

	cout << r * n + c * n - r * c << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}