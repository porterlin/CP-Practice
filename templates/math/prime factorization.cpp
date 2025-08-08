// 樸素計算 n 的質因數分解

vector<i64> base;
vector<i64> exp;

for (i64 i = 2; i * i <= n; i++) {
	if (n % i == 0) {
		int cnt = 0;
		while (n % i == 0) {
			n /= i;
			cnt++;
		}
		base.push_back(i);
		exp.push_back(cnt);
	}
}

if (n > 1) {
	base.push_back(n);
	exp.push_back(1);
}