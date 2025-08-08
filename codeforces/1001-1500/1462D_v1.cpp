#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	i64 sum = 0;
	vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	for (int k = n; k > 0; k--) {
		if (sum % k) {
			continue;
		}

		bool ok = true;
		i64 seg = sum / k, seg_sum = 0;
		for (int i = 0; i < n; i++) {
			if (seg_sum == seg) {
				seg_sum = 0;
			}
			seg_sum += a[i];
			if (seg_sum > seg) {
				ok = false;
				break;
			}
		}

		if (ok) {
			cout << n - k << "\n";
			return;
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