#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ranges::sort(a);

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int rr = upper_bound(a.begin(), a.end(), r - a[i]) - a.begin();
        int ll = lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();
        if (rr >= ll && ll > i) {
            ans += rr - ll;
        } else if (rr > i) {
            ans += rr - i - 1;
        }
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