#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, m, si, sj;
	cin >> n >> m >> si >> sj;

	if (si == 1 && sj == 1)
		cout << n << " " << m << " " << n << " " << m << "\n";
	else if (si == 1 && sj == m)
		cout << n << " " << 1 << " " << n << " " << 1 << "\n";
	else if (si == n && sj == 1)
		cout << 1 << " " << m << " " << 1 << " " << m << "\n";
	else if (si == n && sj == m)
		cout << 1 << " " << 1 << " " << 1 << " " << 1 << "\n";
	else
		cout << 1 << " " << 1 << " " << n << " " << m << "\n";
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