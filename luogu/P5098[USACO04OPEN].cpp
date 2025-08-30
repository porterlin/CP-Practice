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
    int n;
    cin >> n;

    int mx1 = INT_MIN, mn1 = INT_MAX, mx2 = INT_MIN, mn2 = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mx1 = max(mx1, x + y);
        mn1 = min(mn1, x + y);
        mx2 = max(mx2, x - y);
        mn2 = min(mn2, x - y);
    }

    cout << max(mx1 - mn1, mx2 - mn2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}