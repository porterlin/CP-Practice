#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string s1, s2;
	cin >> s1 >> s2;

	int f = count(s1.begin(), s1.end(), '+') - count(s1.begin(), s1.end(), '-');

	double total = pow(2, count(s2.begin(), s2.end(), '?'));
	if (total == 0) {
		int pos = count(s2.begin(), s2.end(), '+') - count(s2.begin(), s2.end(), '-');
		if (pos == f) {
			cout << fixed << setprecision(12) << (double)1 << "\n";
		} else {
			cout << fixed << setprecision(12) << (double)0 << "\n";
		}
		return;
	}

	int cnt = 0;
	auto dfs = [&](this auto&& dfs, int i, int pos) {
		if (i == s2.size()) {
			cnt += (pos == f);
			return;
		}

		if (s2[i] == '+' || s2[i] == '?') {
			dfs(i + 1, pos + 1);
		}
		if (s2[i] == '-' || s2[i] == '?') {
			dfs(i + 1, pos - 1);
		}
	};

	dfs(0, 0);

	cout << fixed << setprecision(12) << cnt / total << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}