#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string s0, s1;
	int n;
	cin >> n >> s0 >> s1;
	vector<vector<char>> a(2, vector<char>(n));
	for (int i = 0; i < n; i++) {
		a[0][i] = s0[i];
	}
	for (int i = 0; i < n; i++) {
		a[1][i] = s1[i];
	}

	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j != 0 && j != n - 1 && a[i][j] == '.' && a[i][j - 1] == '.' && a[i][j + 1] == '.' && a[i + 1][j] == '.' && a[i + 1][j - 1] == 'x' && a[i + 1][j + 1] == 'x') {
				ans++;
			}
			if (i == 1 && j != 0 && j != n - 1 && a[i][j] == '.' && a[i][j - 1] == '.' && a[i][j + 1] == '.' && a[i - 1][j] == '.' && a[i - 1][j - 1] == 'x' && a[i - 1][j + 1] == 'x') {
				ans++;
			}
		}
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