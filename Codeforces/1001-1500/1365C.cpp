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

	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[b[i]] = n + i;
	}
	for (int i = 0; i < n; i++) {
		if (mp[a[i]] - i > n) {
			a[i] = mp[a[i]] - i - n;
		} else {
			a[i] = mp[a[i]] - i;
		}
	}
	int ans = 0;
	unordered_map<int, int> mp1;
	for (auto& v : a) {
		mp1[v]++;
		ans = max(ans, mp1[v]);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}