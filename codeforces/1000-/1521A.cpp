#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 A, B;
	cin >> A >> B;

	if (B == 1) {
		cout << "NO\n";
		return;
	}

	B *= 2;
	cout << "YES\n";
	cout << A << " " << A * (B - 1) << " " << A * B << "\n";
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