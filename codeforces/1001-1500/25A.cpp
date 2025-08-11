#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;

	int oddCnt = 0, evenCnt = 0, oddIdx = 0, evenIdx = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		
		if (a % 2) {
			oddCnt++;
			oddIdx = i + 1;
		} else {
			evenCnt++;
			evenIdx = i + 1;
		}
	}

	if (oddCnt == 1) {
		cout << oddIdx << "\n";
	} else {
		cout << evenIdx << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}