#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	ranges::sort(a);

	for (int i = 0; i < m; i++) {
		cout << upper_bound(a.begin(), a.end(), b[i]) - a.begin() << " \n"[i == m - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}