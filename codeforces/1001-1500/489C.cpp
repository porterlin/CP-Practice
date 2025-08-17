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
    int m, s;
    cin >> m >> s;

    if (9 * m < s || (s < 1 && m > 1)) {
        cout << -1 << " " << -1 << "\n";
        return;
    }

    string mn(m, '0');
    int smn = s;
    if (smn > 0) {
        mn[0] = '1';
        smn--;
    }
    for (int i = m - 1; i >= 0; i--) {
        if (smn >= 9) {
            mn[i] += 9;
            smn -= 9;
        } else {
            mn[i] += smn;
            break;
        }
    }

    string mx(m, '0');
    int smx = s;
    for (int i = 0; i < m; i++) {
        if (smx >= 9) {
            mx[i] += 9;
            smx -= 9;
        } else {
            mx[i] += smx;
            break;
        }
    }

    cout << mn << " " << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}