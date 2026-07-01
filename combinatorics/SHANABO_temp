 ///////////////////////////////////////////////// Combinatorics & Math Template


 ll fact[N], inv_fact[N];
 ll dp1[1005][1005];

 ///////////////////////////////////////////////// Fast Power

 // Use:
 // - Binary exponentiation
 // - Modular inverse
 // - Huge powers

 // Time: O(log n)
 // Space: O(1)

 ll modPow(ll x, ll n, ll mod = MOD) {
     x %= mod;

     ll res = 1;

     while (n > 0) {
         if (n & 1)
             res = res * x % mod;

         x = x * x % mod;

         n >>= 1;
     }

     return res;
 }

 ///////////////////////////////////////////////// Modular Inverse

 // Use:
 // - Division under modulo
 // - nCr modulo prime

 // Time: O(log MOD)
 // Space: O(1)

 ll modInverse(ll x, ll mod = MOD) {
     return modPow(x, mod - 2, mod);
 }

 ///////////////////////////////////////////////// Precompute Factorials

 // Use:
 // - nCr modulo
 // - nPr modulo

 // Time: O(N)
 // Space: O(N)

 void factorial(ll mod = MOD) {
     fact[0] = 1;

     for (int i = 1; i < N; i++)
         fact[i] = fact[i - 1] * i % mod;
 }

 ///////////////////////////////////////////////// Precompute Inverse Factorials

 // Time: O(N + log MOD)
 // Space: O(N)

 void inv_factorial(ll mod = MOD) {
     inv_fact[N - 1] = modInverse(fact[N - 1], mod);

     for (int i = N - 1; i >= 1; i--)
         inv_fact[i - 1] = inv_fact[i] * i % mod;
 }

 ///////////////////////////////////////////////// Preprocess

 // Use before NCR/NPR

 // Time: O(N + log MOD)
 // Space: O(N)

 void pre_process(ll mod = MOD) {
     factorial(mod);

     inv_factorial(mod);
 }

 ///////////////////////////////////////////////// nCr Modulo

 // Use:
 // - Combinations
 // - Counting subsets
 // - Large constraints

 // Time: O(1)
 // Space: O(1)

 ll NCR(ll n, ll r, ll mod = MOD) {
     if (r > n || r < 0)
         return 0;

     return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
 }

 ll nC2(ll n) {
     return n * (n - 1) / 2;
 }

 ///////////////////////////////////////////////// nPr Modulo

 // Use:
 // - Ordered arrangements
 // - Permutations

 // Time: O(1)
 // Space: O(1)

 ll NPR(ll n, ll r, ll mod = MOD) {
     if (r > n || r < 0)
         return 0;

     return fact[n] * inv_fact[n - r] % mod;
 }

 ///////////////////////////////////////////////// nCr Direct

 // Use:
 // - Small values
 // - Exact answer without modulo

 // Time: O(k)
 // Space: O(1)

 ll C(ll n, ll k) {
     if (k > n)
         return 0;

     k = min(k, n - k);

     ll res = 1;

     for (ll i = 1; i <= k; i++) {
         res *= (n - k + i);

         res /= i;
     }

     return res;
 }

 ///////////////////////////////////////////////// nCr Double

 // Use:
 // - Large combinations
 // - Avoid overflow sometimes

 // Time: O(k)
 // Space: O(1)

 ll C2(ll n, ll k) {
     if (k > n)
         return 0;

     double res = 1;

     for (int i = 1; i <= k; i++)
         res = res * (n - k + i) / i;

     return (ll) (res + 0.01);
 }

 ///////////////////////////////////////////////// Pascal Triangle Recursive

 // Use:
 // - Small constraints
 // - DP learning

 // Time: O(n * r)
 // Space: O(n * r)

 ll nCr_rec(ll n, ll r) {
     if (n < r)
         return 0;

     if (n == r || r == 0)
         return 1;

     ll &ret = dp1[n][r];

     if (~ret)
         return ret;

     return ret =
            nCr_rec(n - 1, r - 1)
            + nCr_rec(n - 1, r);
 }

 ///////////////////////////////////////////////// Pascal Triangle Iterative

 // Use:
 // - Build all combinations
 // - Small constraints

 // Time: O(n * r)
 // Space: O(n * r)

 // ll nCr_iter(ll n, ll r) {
 //
 //     if (n < r)
 //         return 0;
 //
 //     vector<vector<ll>> dp(n + 1,
 //                           vector<ll>(r + 1));
 //
 //     dp[0][0] = 1;
 //
 //     for (int i = 0; i < n; i++) {
 //
 //         for (int j = 0;
 //              j <= min(i, r); j++) {
 //
 //             dp[i + 1][j] += dp[i][j];
 //
 //             if (j < r)
 //                 dp[i + 1][j + 1] += dp[i][j];
 //         }
 //     }
 //
 //     return dp[n][r];
 // }

 ///////////////////////////////////////////////// Pascal Triangle Full Table

 // Use:
 // - Generate all nCr values

 // Time: O(n^2)
 // Space: O(n^2)

 vector<vector<ll> > pascal(int n) {
     vector<vector<ll> > C(n + 1,
                           vector<ll>(n + 1));

     for (int i = 0; i <= n; i++) {
         C[i][0] = C[i][i] = 1;

         for (int j = 1; j < i; j++)
             C[i][j] =
                     C[i - 1][j - 1]
                     + C[i - 1][j];
     }

     return C;
 }

 ///////////////////////////////////////////////// Catalan Number

 // Use:
 // - Balanced brackets
 // - Binary trees
 // - Polygon triangulation

 // Time: O(1)
 // Space: O(1)

 ll catalan(ll n) {
     return NCR(2 * n, n)
            * modInverse(n + 1) % MOD;
 }

 ///////////////////////////////////////////////// Stars and Bars

 // Use:
 // - x1 + x2 + ... + xn = k
 // - Distribution problems

 // Time: O(1)
 // Space: O(1)

 ll stars_bars(ll n, ll k) {
     return NCR(n + k - 1, k);
 }

 ///////////////////////////////////////////////// Derangement

 // Use:
 // - No element stays in place

 // Time: O(n)
 // Space: O(n)

 ll derangement(int n) {
     vector<ll> d(n + 1);

     d[0] = 1;

     if (n >= 1)
         d[1] = 0;

     for (int i = 2; i <= n; i++)

         d[i] =
                 (i - 1)
                 * (d[i - 1] + d[i - 2])
                 % MOD;

     return d[n];
 }

 ///////////////////////////////////////////////// Lucas Theorem

 // Use:
 // - nCr for huge n
 // - n up to 1e18
 // - Small prime modulo

 // Time: O(log_p n)
 // Space: O(log_p n)

 ll lucas(ll n, ll r, ll p) {
     if (r == 0)
         return 1;

     return NCR(n % p, r % p, p)
            * lucas(n / p, r / p, p)
            % p;
 }

 ///////////////////////////////////////////////// Matrix Fibonacci

 // Use:
 // - Huge Fibonacci
 // - Linear recurrence

 // Time: O(log n)
 // Space: O(1)

 struct Matrix {
     ll a, b, c, d;

     Matrix operator*(const Matrix &o) {
         return {

             (a * o.a + b * o.c) % MOD,

             (a * o.b + b * o.d) % MOD,

             (c * o.a + d * o.c) % MOD,

             (c * o.b + d * o.d) % MOD
         };
     }
 };

 Matrix matPow(Matrix base, ll n) {
     Matrix res = {1, 0, 0, 1};

     while (n) {
         if (n & 1)
             res = res * base;

         base = base * base;

         n >>= 1;
     }

     return res;
 }

 ll fib(ll n) {
     if (n == 0)
         return 0;

     Matrix m = {1, 1, 1, 0};

     return matPow(m, n - 1).a;
 }

 // ==========================================================//
