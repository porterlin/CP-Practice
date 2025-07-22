#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int x;
	cin >> x;

	int jump = 0, sum = 0;;
	while (sum < x) {
		sum += ++jump;
	}

	if (sum - 1 == x) {
		jump++;
	}

	cout << jump << "\n";
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