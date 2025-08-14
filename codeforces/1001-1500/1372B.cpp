#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    i64 n;
    cin >> n;

    i64 a = 1;
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a = n / i;
            break;
        }
    }

    cout << a << " " << n - a << "\n";
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