#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	i64 k;
	cin >> k;

	priority_queue<i64, vector<i64>, greater<>> pq;
	for (int i = 0; i < 10; i++) {
		pq.push(1);
	}
	i64 num = 1;
	while (num < k) {
		i64 a = pq.top();
		pq.pop();
		pq.push(a + 1);
		num = num / a * (a + 1);
	}

	string s = "codeforces";
	for (i64 i = 0; i < 10; i++) {
		i64 n = pq.top();
		pq.pop();
		for (i64 j = 0; j < n; j++) {
			cout << s[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}