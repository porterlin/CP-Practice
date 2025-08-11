#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (!mp.contains(s)) {
			mp[s]++;
			cout << "OK\n";
		} else {
			cout << s << mp[s] << "\n";
			mp[s]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}