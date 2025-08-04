#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string s;
	cin >> s;
	for (int i = 0, cnt = 0; i < s.size(); i++) {
		if (s[i] == '#') {
			cnt++;
			cout << i + 1;
			if (cnt == 1) {
				cout << ",";
			} else if (cnt == 2) {
				cout << "\n";
				cnt = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}