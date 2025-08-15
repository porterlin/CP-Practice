#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int MOD = 1e9 + 7;

void solve() {
    i64 x, y, n;
    cin >> x >> y >> n;

    vector<i64> f(6);
    f[0] = x, f[1] = y;
    for (i64 i = 2; i < 6; i++) {
        f[i] = f[i - 1] - f[i - 2];
    }

    cout << (f[(n - 1) % 6] % MOD + MOD) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}