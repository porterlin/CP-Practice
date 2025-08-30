#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int q;
    cin >> q;

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 2) {
            cout << pq.top() << "\n";
            pq.pop();
        } else {
            int x;
            cin >> x;
            pq.push(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}