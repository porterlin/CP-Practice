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

double calDist(i64 x, i64 y, i64 x1, i64 y1) {
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

void solve() {
    i64 r, x, y, x1, y1;
    cin >> r >> x >> y >> x1 >> y1;

    double dis = calDist(x, y, x1, y1);

    if (x == x1 && y == y1) {
        cout << 0 << "\n";
    } else if (dis <= r) {
        cout << 1 << "\n";
    } else {
        cout << ceil(dis / (2 * r)) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}