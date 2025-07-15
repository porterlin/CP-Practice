#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	string num;
	int n, m;
	cin >> n >> num >> m;

	int ten = 0;
	for (int i = num.size() - 1; i >= 0; i--) {
		if (isalpha(num[i]))
			ten += (num[i] - 'A' + 10) * pow(n, num.size() - 1 - i);
		else
			ten += (num[i] - '0') * pow(n, num.size() - 1 - i);
	}

	string ans;
	while (ten > 0) {
		int r = ten % m;
		if (r > 9) {
			ans.push_back(r - 10 + 'A');
		} else {
			ans.push_back(r + '0');
		}
		ten /= m;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}