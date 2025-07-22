#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, k;
	cin >> n >> k;

	int a, b, c;
	if (n % 2 == 1) {
		a = 1;
		b = c = (n - 1) / 2;
	} else if (n % 4 == 0) {
		a = n / 2;
		b = c = n / 4;
	} else {
		a = 2;
		b = c = (n - 2) / 2;
	}
	cout << a << " " << b << " " << c << "\n";
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