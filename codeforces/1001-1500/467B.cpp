#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, m, k, fedor;
	cin >> n >> m >> k;
	vector<int> vec(m);
	for (int i = 0; i < m; i++) {
		cin >> vec[i];
	}
	cin >> fedor;

	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (popcount((u32)(vec[i] ^ fedor)) <= k)
			ans++;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}