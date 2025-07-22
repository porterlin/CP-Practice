#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	bool ok = true;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			ok = false;
			break;
		}
	}

	if (ok) {
		cout << "Yes\n";
		return;
	}

	int sum = accumulate(b.begin(), b.end(), 0);
	if (sum == n || sum == 0)
		cout << "No\n";
	else
		cout << "Yes\n";
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