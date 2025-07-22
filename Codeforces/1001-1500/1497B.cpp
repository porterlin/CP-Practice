#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, m, a;
	cin >> n >> m;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mp[a % m]++;
	}

	int ans = mp.size();
	for (auto& [key, val] : mp) {
		if (mp.contains(m - key) && mp[m - key] != -1e9) {
			if (m - key == key) {
				continue;
			} else if (abs(val - mp[m - key]) < 2) {
				ans--;
			} else {
				ans += abs(val - mp[m - key]) - 2;
			}
			val = -1e9;
		} else if (!mp.contains(m - key)) {
			if (key != 0)
				ans += val - 1;
		}
	}
	cout << ans << "\n";
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