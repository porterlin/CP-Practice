#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int m;
	cin >> m;
	vector<vector<int>> mat(2, vector<int>(m));
	for (int i = 0; i < m; i++) {
		cin >> mat[0][i];
	}
	for (int i = 0; i < m; i++) {
		cin >> mat[1][i];
	}

	vector<int> up(m + 1), down(m + 1);
	for (int i = 0; i < m; i++) {
		down[i + 1] = down[i] + mat[1][i];
	}
	for (int i = m - 1; i >= 0; i--) {
		up[i] = up[i + 1] + mat[0][i];
	}

	int ans = INT_MAX;
	for (int i = 0; i < m; i++) {
		int buf = max(down[i], up[i + 1]);
		ans = min(ans, buf);
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