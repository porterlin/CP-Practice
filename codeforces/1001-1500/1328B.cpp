#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        if (k > i) {
            k -= i;
        } else {
            cout << string(n - i - 1, 'a') << 'b' << string(i - k, 'a') << 'b' << string(k - 1, 'a') << "\n";
            break;
        }
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