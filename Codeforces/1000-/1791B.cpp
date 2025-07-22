#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string s;
	int n;
	cin >> n >> s;

	int si = 0, sj = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			si--;
		} else if (s[i] == 'R') {
			si++;
		} else if (s[i] == 'U') {
			sj++;
		} else {
			sj--;
		}

		if (si == 1 && sj == 1) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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