#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string line;
	int n, t;
	cin >> n >> t >> line;

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (line[j] == 'B' && line[j + 1] == 'G') {
				swap(line[j], line[j + 1]);
				j++;
			}
		}
	}

	cout << line << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}