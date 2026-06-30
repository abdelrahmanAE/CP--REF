vector<pair<int, int> > getPrimeFactors(ll n) { // O(sqrt(n))
  vector<pair<int, int> > ret;
  for (int p = 2; p * p <= n; p++) {
    int e = 0;
    while (n % p == 0) {
      n /= p;
      e++;
    }
    if (e > 0) {
      ret.push_back({p, e});
    }
  }
  if (n > 1) {
    ret.push_back({n, 1});
  }
  return ret;
}
