#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n;
	cin >> n;
	vector<i64> b(n + 2);
	for (i64 i = 0; i < n + 2; i++) {
		cin >> b[i];
	}

	ranges::sort(b);

	i64 sum = accumulate(b.begin(), b.end(), 0LL);
	bool ok = false;
	for (i64 i = 0; i < n + 2; i++) {
		if (i != n + 1 && sum - b[i] == b[n + 1] * 2) {
			b[i] = 0;
			ok = true;
			break;
		}
		if (i == n + 1 && sum - b[i] == b[n] * 2) {
			b[i] = 0;
			ok = true;
			break;
		}
	}

	if (!ok) {
		cout << -1 << "\n";
	} else {
		i64 cnt = 0;
		for (i64 i = 0; i < n + 2 && cnt < n; i++) {
			if (b[i] == 0) {
				continue;
			}
			if (cnt == n - 1)
				cout << b[i] << "\n";
			else
				cout << b[i] << " ";
			cnt++;
		}
	}
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