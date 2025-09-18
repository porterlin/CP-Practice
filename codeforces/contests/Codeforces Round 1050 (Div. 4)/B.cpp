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
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a >= y) {
            break;
        }
        ans++;
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        if (b >= x) {
            break;
        }
        ans++;
    }

    cout << ans << "\n";
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