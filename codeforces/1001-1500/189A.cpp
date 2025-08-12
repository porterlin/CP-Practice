#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	int ans = 0;
	for (int i = 0; i * a <= n; i++) {
		int t = n - i * a;
		for (int j = 0; j * b <= t; j++) {
			if ((t - j * b) % c == 0) {
				ans = max(ans, i + j + (t - j * b) / c);
			}
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}