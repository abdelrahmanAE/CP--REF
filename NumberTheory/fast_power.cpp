int power(ll a, ll b) { // O(b)
  if (b == 0) return 1;
  return a * power(a, b - 1);
}

// Fast Power, Fast Exponentiation
int fPower(ll a, ll p) {  // O(log(b))
  if (b == 0) return 1;
  ll p = fPower(a, b >> 1);
  return (b & 1) ? p * p * a : p * p;
}

const ll MOD=1e9+7;
int fPower(ll a, ll p) { // with mod
    int res = 1;
    while (p > 0) {
        if (p&1) res = (res * a)%MOD;
        a = (a * a)%MOD;
        p /= 2;
    }
    return res;
}
ll inv(ll a) {
    return power(a, MOD - 2);
}
