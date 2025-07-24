#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string s;
	cin >> s;
	int cntf = 0, cntt = 0, cntn = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'F')
			cntf++;
		else if (s[i] == 'T')
			cntt++;
		else if (s[i] == 'N')
			cntn++;
	}

	string ans;
	for (int i = 0; i < cntt; i++) {
		ans.push_back('T');
	}
	for (int i = 0; i < cntf; i++) {
		ans.push_back('F');
	}
	for (int i = 0; i < cntn; i++) {
		ans.push_back('N');
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'F' && s[i] != 'T' && s[i] != 'N') {
			ans.push_back(s[i]);
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