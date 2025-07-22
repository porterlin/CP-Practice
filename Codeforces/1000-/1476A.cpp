#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, k;
	cin >> n >> k;

	if (n % k == 0) {
		cout << 1 << "\n";
		return;
	}

	int r = k * (n / k + 1);

	if (r % n == 0)
		cout << r / n << "\n";
	else
		cout << r / n + 1 << "\n";
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