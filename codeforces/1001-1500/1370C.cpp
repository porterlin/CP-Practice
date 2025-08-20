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

    if (n == 1) {
        cout << "FastestFinger\n";
        return;
    } else if (n % 2 == 1 || n == 2) {
        cout << "Ashishgup\n";
        return;
    }

    int cnt = 0, cnt2 = 0;
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
                if (i % 2 == 1) {
                    cnt++;
                } else if (i == 2) {
                    cnt2++;
                }
            }
        }
    }
    if (n > 1) {
        cnt++;
    }

    if (cnt == 0 || (cnt2 == 1 && cnt == 1)) {
        cout << "FastestFinger\n";
    } else {
        cout << "Ashishgup\n";
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