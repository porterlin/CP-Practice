vector<bool> is_prime;
vector<int> primes;

void sieve(int n) {
	is_prime.assign(n + 1, 1);
	primes.clear();
	is_prime[0] = is_prime[1] = 0;

	for (int i = 2; i <= n; i++) {
		if (is_prime[i])
			primes.push_back(i);

		for (int p : primes) {
			if (i * p > n)
				break;
			is_prime[i * p] = 0;
			if (i % p == 0)
				break;
		}
	}
}