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

    int num[10]{};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        num[a % 10]++;
    }

    for (int i = 0; i < 10; i++) {
        if (num[i] == 0) {
            continue;
        }
        for (int j = 0; j < 10; j++) {
            if (j == i && num[j] < 2) {
                continue;
            }
            for (int k = 0; k < 10; k++) {
                if ((k == i && num[k] < 2)|| (k == j && num[k] < 2) || (k == i && k == j && num[k] < 3)) {
                    continue;
                }
                if (num[i] != 0 && num[j] != 0 && num[k] != 0 && (i + j + k) % 10 == 3) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }

    cout << "NO\n";
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