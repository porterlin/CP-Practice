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

class DSU {
public:
    vector<int> parent;
    vector<int> c;

    DSU(int n): parent(n), c(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        parent[x] = y;
        c[y] = min(c[y], c[x]);
        c[x] = INT_MAX;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        cin >> dsu.c[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        dsu.merge(x, y);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.c[i] != INT_MAX) {
            ans += dsu.c[i];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}