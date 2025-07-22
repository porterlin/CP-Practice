#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int x, y, z;
	cin >> x >> y >> z;

	int b = sqrt(x * y / z);
	int a = x / b;
	int c = z / a;
	cout << (a + b + c) * 4 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}