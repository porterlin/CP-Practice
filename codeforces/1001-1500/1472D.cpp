#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<>> odd;
	priority_queue<int, vector<int>, less<>> even;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a % 2) {
			odd.push(a);
		} else {
			even.push(a);
		}
	}

	i64 alice = 0, bob = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (!odd.empty() && !even.empty()) {
				if (even.top() >= odd.top()) {
					alice += even.top();
					even.pop();
				} else {
					odd.pop();
				}
			} else if (!even.empty()) {
				alice += even.top();
				even.pop();
			} else {
				odd.pop();
			}
		} else {
			if (!odd.empty() && !even.empty()) {
				if (odd.top() >= even.top()) {
					bob += odd.top();
					odd.pop();
				} else {
					even.pop();
				}
			} else if (!odd.empty()) {
				bob += odd.top();
				odd.pop();
			} else {
				even.pop();
			}
		}
	}

	if (alice > bob) {
		cout << "Alice\n";
	} else if (alice < bob) {
		cout << "Bob\n";
	} else {
		cout << "Tie\n";
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