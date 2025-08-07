#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	i64 ans = 0;
	unordered_map<int, i64> mp;
	for (int i = 0; i < n; i++) {
		if (mp.contains(i - a[i])) {
			ans += mp[i - a[i]];
		}
		mp[a[i] + i]++;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}