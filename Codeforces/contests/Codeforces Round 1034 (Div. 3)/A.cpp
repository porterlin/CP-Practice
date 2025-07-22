#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	if (n < 4) {
		cout << "Alice\n";
		return;
	}

	int a = n % 4;
	if (a == 0)
		cout << "Bob\n";
	else
		cout << "Alice\n";
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