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
    i64 x;
    cin >> x;

    i64 a = 1, b = x;
    for (i64 i = 2; i * i <= x; i++) {
        if (x % i == 0 && lcm(i, x / i) == x) {
            a = i;
            b = x / i;
        }
    }

    cout << a << " " << b << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}