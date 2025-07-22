#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	ranges::sort(vec);

	if (n == 2) {
		cout << vec[0] << " " << vec[1] << "\n";
		return;
	}

	int mn = INT_MAX;
	int a;
	for (int i = 1; i < n; i++) {
		if (vec[i] - vec[i - 1] < mn) {
			mn = vec[i] - vec[i - 1];
			a = i;
		}
	}

	for (int i = a; i < n; i++) {
		cout << vec[i] << " ";
	}
	for (int i = 0; i < a; i++) {
		cout << vec[i] << " \n"[i == a - 1];
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