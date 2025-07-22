#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string str, buf;
	getline(cin, str);
	stringstream ss(str);
	int ch[26] {};

	while (getline(ss, buf, ',')) {
		if (isalpha(buf[1]))
			ch[buf[1] - 'a'] = 1;
	}

	cout << accumulate(begin(ch), end(ch), 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}