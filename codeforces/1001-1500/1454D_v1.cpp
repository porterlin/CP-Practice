#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 n;
	cin >> n;

	vector<i64> base, exp;

	for (i64 i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			base.push_back(i);
			exp.push_back(cnt);
		}
	}

	if (n > 1) {
		base.push_back(n);
		exp.push_back(1);
	}

	i64 idx = max_element(exp.begin(), exp.end()) - exp.begin();
	cout << exp[idx] << "\n";

	for (i64 i = 0; i < exp[idx] - 1; i++) {
		cout << base[idx] << " ";
	}

	exp[idx] = 1;
	i64 end = 1;
	for (i64 i = 0; i < base.size(); i++) {
		while (exp[i]--) {
			end *= base[i];
		}
	}

	cout << end << "\n";
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