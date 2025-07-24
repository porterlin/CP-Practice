#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

template<class T>
constexpr T power(T a, i64 b) {
	T res = 1;
	while (b > 0) {
		if (b & 1) {
			res *= a;
		}
		a *= a;
		b >>= 1;
	}
	return res;
}

template<int M>
struct ModInt {
public:
	constexpr ModInt() : x(0) {}

	template<std::signed_integral T>
	constexpr ModInt(T x_) {
		T v = x_ % M;
		if (v < 0) {
			v += M;
		}
		x = v;
	}

	constexpr int val() const {
		return x;
	}

	constexpr ModInt operator-() const {
		ModInt res;
		res.x = (x == 0 ? 0 : M - x);
		return res;
	}

	constexpr ModInt inv() const {
		return power(*this, M - 2);
	}

	constexpr ModInt &operator*=(const ModInt &rhs) & {
		x = i64(x) * rhs.val() % M;
		return *this;
	}

	constexpr ModInt &operator+=(const ModInt &rhs) & {
		x += rhs.val();
		if (x >= M) {
			x -= M;
		}
		return *this;
	}

	constexpr ModInt &operator-=(const ModInt &rhs) & {
		x -= rhs.val();
		if (x < 0) {
			x += M;
		}
		return *this;
	}

	constexpr ModInt &operator/=(const ModInt &rhs) & {
		return *this *= rhs.inv();
	}

	friend constexpr ModInt operator*(ModInt lhs, const ModInt &rhs) {
		lhs *= rhs;
		return lhs;
	}

	friend constexpr ModInt operator+(ModInt lhs, const ModInt &rhs) {
		lhs += rhs;
		return lhs;
	}

	friend constexpr ModInt operator-(ModInt lhs, const ModInt &rhs) {
		lhs -= rhs;
		return lhs;
	}

	friend constexpr ModInt operator/(ModInt lhs, const ModInt &rhs) {
		lhs /= rhs;
		return lhs;
	}

	friend constexpr std::istream &operator>>(std::istream &is, ModInt &a) {
		i64 i;
		is >> i;
		a = i;
		return is;
	}

	friend constexpr std::ostream &operator<<(std::ostream &os, const ModInt &a) {
		return os << a.val();
	}

	friend constexpr std::strong_ordering operator<=> (ModInt lhs, ModInt rhs) {
		return lhs.val() <=> rhs.val();
	}

private:
	int x;
};

constexpr int M = 998244353;
using Z = ModInt<M>;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<array<int, 4>> seg(n);
	for (int i = 0; i < n; i++) {
		cin >> seg[i][0] >> seg[i][1] >> seg[i][2] >> seg[i][3];
		seg[i][0]--;
		seg[i][1]--;
	}

	vector<Z> c(m, 1);
	for (auto& [l, r, p, q] : seg) {
		c[r] *= (q - p);
		c[r] /= q;
	}
	vector<Z> pre(m + 1, 1);
	for (int i = 0; i < m; i++) {
		pre[i + 1] = pre[i] * c[i];
	}

	ranges::sort(seg);
	vector<Z> dp(m + 1);
	dp[0] = 1;
	for (auto& [l, r, p, q] : seg) {
		if (dp[l].val() == 0)
			continue;
		dp[r + 1] += dp[l] * p / (q - p) * (pre[r + 1] / pre[l]);
	}
	cout << dp[m] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}