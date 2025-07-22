#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		if (i < s.size() - 1 && s[i] == s[i + 1]) {
			cout << char((s[i] - 'a' + 1) % 26 + 'a');
			for (int j = i + 1; j < s.size(); j++) {
				cout << s[j];
			}
			cout << "\n";
			return;
		}
	}
	cout << char((s[s.size() - 1] - 'a' + 1) % 26 + 'a') << "\n";
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