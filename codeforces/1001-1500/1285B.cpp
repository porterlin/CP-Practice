#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<i64> dp1(n - 1), dp2(n);
    dp1[0] = a[0];
    for (int i = 1; i < n - 1; i++) {
        dp1[i] = max(a[i], dp1[i - 1] + a[i]);
    }
    dp2[1] = a[1];
    for (int i = 2; i < n; i++) {
        dp2[i] = max(a[i], dp2[i - 1] + a[i]);
    }
 
    i64 yasser = accumulate(a.begin(), a.end(), 0LL);
    i64 adel = max(ranges::max(dp1), ranges::max(dp2));

    cout << (yasser > adel ? "YES\n" : "NO\n");
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