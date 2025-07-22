#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int s[9][9] {};
	for (int i = 0; i < 9; i++) {
		string str;
		cin >> str;
		str.erase(9, 1);
		for (int j = 0; j < 9; j++) {
			s[i][j] = str[j] - '0';
		}
	}

	s[0][0] = (s[0][0] + 1) % 9 + 1;
	s[3][1] = (s[3][1] + 1) % 9 + 1;
	s[6][2] = (s[6][2] + 1) % 9 + 1;
	s[1][3] = (s[1][3] + 1) % 9 + 1;
	s[4][4] = (s[4][4] + 1) % 9 + 1;
	s[7][5] = (s[7][5] + 1) % 9 + 1;
	s[2][6] = (s[2][6] + 1) % 9 + 1;
	s[5][7] = (s[5][7] + 1) % 9 + 1;
	s[8][8] = (s[8][8] + 1) % 9 + 1;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << s[i][j];
		}
		cout << "\n";
	}
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