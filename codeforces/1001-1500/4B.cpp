#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int d, st, sum = 0, sum1 = 0;
	cin >> d >> st;
	vector<array<int, 2>> a(d);
	for (int i = 0; i < d; i++) {
		cin >> a[i][0] >> a[i][1];
		sum += a[i][1];
		sum1 += a[i][0];
	}

	if (sum < st || sum1 > st) {
		cout << "NO\n";
		return;
	}

	for (int i = 0; i < d; i++) {
		if (sum1 == st)
			break;
		if (sum1 + a[i][1] - a[i][0] <= st) {
			sum1 += a[i][1] - a[i][0];
			a[i][0] = a[i][1];
		} else if (sum1 + a[i][1] - a[i][0] > st) {
			a[i][0] += st - sum1;
			sum1 = st;
		}
	}

	cout << "YES\n";
	for (int i = 0; i < d; i++) {
		cout << a[i][0] << " \n"[i == d - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}