#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y;

    for (int i = 0; i < n; i++) {
        cin >> a;
    }
    for (int i = 0; i < m; i++) {
        cin >> b;
    }

    cout << n + m << "\n";
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