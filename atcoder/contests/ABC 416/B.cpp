#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string s;
	cin >> s;

	bool ok = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '#') {
			ok = true;
		} else if (s[i] == '.' && ok) {
			s[i] = 'o';
			ok = false;
		}
	}
	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}