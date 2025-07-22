#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, cnt = 0;
	string str;
	cin >> n >> str;

	if (n == 1) {
		cout << "BOB\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (str[i] == '0')
			cnt++;
	}

	if (n % 2 == 1 && str[n / 2] == '0' && cnt > 1)
		cout << "ALICE\n";
	else
		cout << "BOB\n";
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