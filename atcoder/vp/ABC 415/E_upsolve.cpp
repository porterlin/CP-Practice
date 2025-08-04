#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 INF = 1e18;
constexpr i64 NINF = -1e18;

void solve() {
	int h, w;
	cin >> h >> w;
	vector<vector<i64>> a(h, vector<i64>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	vector<i64> p(h + w - 1);
	for (int i = 0; i < h + w - 1; i++) {
		cin >> p[i];
	}

	i64 ans = 0, l = 0, r = INF;
	while (l <= r) {
		i64 mid = r - (r - l) / 2;

		vector<vector<i64>> dp(h, vector<i64>(w, NINF));
		dp[0][0] = mid + a[0][0] - p[0];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i > 0 && dp[i - 1][j] >= 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j] - p[i + j]);
				}
				if (j > 0 && dp[i][j - 1] >= 0) {
					dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j] - p[i + j]);
				}
			}
		}

		if (dp[h - 1][w - 1] < 0) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << l << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}