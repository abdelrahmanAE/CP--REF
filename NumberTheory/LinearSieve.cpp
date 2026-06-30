/*
Linear Sieve (Euler Sieve)

Time: O(N)
Memory: O(N)

- Finds all primes.
- Computes SPF (Smallest Prime Factor) for every number.
- Each composite number is processed exactly once.
- Condition: primes[j] <= spf[i] ensures uniqueness.
- Useful for fast prime factorization in O(log N).
*/
const int N = 1e7 + 9;

int spf[N];
vector<int> primes;
void sieve() {
  for(int i = 2; i < N; i++) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}
