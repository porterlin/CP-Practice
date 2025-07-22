#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n, neg = 0, pos = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0)
			neg++;
		if (a[i] > 0)
			pos++;
	}

	bool ok2 = false, ok3 = false;
	int cnt = 0;
	if (neg % 2 == 0)
		ok3 = true;
	vector<vector<int>> ans(3);
	for (int i = 0; i < n; i++) {
		if ((a[i] > 0 && !ok2) || (pos == 0 && cnt < 2 && a[i] < 0)) {
			ans[1].push_back(a[i]);
			if (a[i] < 0) {
				cnt++;
			} else {
				ok2 = true;
			}
		} else if (a[i] == 0 || (a[i] < 0 && ok3)) {
			ans[2].push_back(a[i]);
			ok3 = false;
		} else {
			ans[0].push_back(a[i]);
		}
	}

	for (int i = 0; i < 3; i++) {
		int size = ans[i].size();
		cout << size << " ";
		for (int j = 0; j < size; j++) {
			cout << ans[i][j] << " \n"[j == size - 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}