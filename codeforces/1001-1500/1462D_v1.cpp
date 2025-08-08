#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	auto check_equal = [](vector<i64>& a) -> bool {
		for (int i = 1; i < a.size(); i++) {
			if (a[i] != a[i - 1]) {
				return false;
			}
		}
		return true;
	};

	int cnt = 0;
	while (!check_equal(a)) {
		// for (auto& b : a) {
		// 	cout << b << " ";
		// }
		// cout << endl;
		i64 idx = min_element(a.begin(), a.end()) - a.begin();
		if (idx == 0) {
			a[idx + 1] += a[idx];
		} else if (idx == a.size() - 1) {
			a[idx - 1] += a[idx];
		} else {
			if (a[idx - 1] < a[idx + 1]) {
				a[idx - 1] += a[idx];
			} else {
				a[idx + 1] += a[idx];
			}
		}
		a.erase(a.begin() + idx);
		cnt++;
	}

	cout << cnt << "\n";
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