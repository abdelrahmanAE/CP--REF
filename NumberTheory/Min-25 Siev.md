# Min-25 Sieve - ECPC Reference

الـ Min-25 Sieve هي خوارزمية بتحسب الـ Prefix sum لدالة $f(x)$ مضروبة (Multiplicative) لحد رقم كبير جداً $N$.

## 1. Complexity
*   **Time Complexity:** $\approx O(N^{3/4} / \log N)$ أو نظرياً $O(N^{1 - \epsilon})$. في المسابقات بيعدي براحة لحد $N \le 10^{11}$ في ثانية أو ثانيتين.
*   **Space / Memory:** $O(\sqrt{N})$. بنحتاج Arrays حجمها تقريباً $2 \times \sqrt{N}$ عشان كده مفيش خوف من الـ Memory Limit.

## 2. إزاي تلقط المسألة في الـ Contest؟
لو لقيت الشروط دي متجمعة، بنسبة 99% دي مسألة Min-25:
1.  **الـ $N$ مرعبة:** الـ $N$ من $10^{9}$ لـ $10^{11}$. لو $N = 10^7$، استخدم Linear Sieve عادي $O(N)$.
2.  **مجموع لدالة:** بيطلب $\sum_{i=1}^{N} f(i)$.
3.  **الدالة Multiplicative:** يعني لو $\gcd(a, b) = 1$، يبقى $f(a \times b) = f(a) \times f(b)$.
4.  **تصرف الدالة مع الـ Primes:** 
    *   عند الـ Prime $p$: الدالة $f(p)$ عبارة عن كثيرة حدود (Polynomial) بسيطة. زي $1$ أو $p$ أو $p^2 - p$.
    *   عند الـ Prime Power $p^e$: تقدر تحسب $f(p^e)$ في $O(1)$ أو $O(e)$ من غير ما تحتاج تلف على الـ $e$.
5.  **أشهر الدوال:** Euler Totient $\phi(x)$، Mobius $\mu(x)$، Sum of Divisors $\sigma(x)$، Number of Divisors $d(x)$.

## 3. إزاي الخوارزمية بتشتغل؟ (The Intuition)
الخوارزمية بتتقسم لخطوتين أساسيتين. فكرتها إننا بنقسم الأرقام لـ Primes و Composites.

### Phase 1: معالجة الأرقام الأولية (The `g` Array)
هدفنا نحسب مجموع $f(p)$ لكل الأرقام الأولية اللي $\le x$. بنعمل ده لكل الـ $x$ اللي على شكل $\lfloor N / i \rfloor$ (وعددهم بيكون $2\sqrt{N}$).
*   بنعتبر في البداية إن كل الأرقام من 2 لـ $x$ هي أرقام أولية (Primes).
*   بعدين بنعمل DP شبه الـ Sieve: بنلف على كل Prime $p$ لحد $\sqrt{N}$، ونطرح مساهمة مضاعفات الـ $p$ (زي ما بنشطب في الـ Sieve العادي).
*   **الـ State:** `g[x]` بتمثل مجموع $f(i)$ بافتراض إن الـ $i$ يا إما Prime يا إما أصغر Prime factor ليه أكبر من $p$.

### Phase 2: تجميع كل الأرقام (The `yo` Function)
دلوقتي إحنا معانا مجاميع الـ Primes جاهزة في הـ `g`.
*   بنبني الدالة الـ Recursive اللي اسمها `yo(x, j)`.
*   الدالة دي بتجمع: (مجموع الـ Primes اللي $\le x$ وأكبر من $p_j$) + (مساهمة الأرقام المركبة Composites).
*   بنجيب الـ Composites إزاي؟ بنجرب كل Prime أكبر من $p_j$ وكل الأسس بتاعته $p^e$، ونضرب $f(p^e)$ في الـ Recursion.

## 4. أشهر الـ Tricks واللعب في المسائل

### Trick 1: الـ $f(p)$ مكونة من كذا حد (Polynomial with multiple terms)
*   **المشكلة:** لو $f(p) = p^2 - p$، مش هينفع نحسبها في Array واحدة في Phase 1.
*   **الحل:** بنعمل 2 Arrays. واحدة `g1` عشان نحسب مجموع الـ $p^2$، وواحدة `g2` عشان نحسب مجموع الـ $p$. كل واحدة بتتحسب وتتعملها Transitions لوحدها.
*   **في Phase 2:** قبل ما ندخل على الـ `yo`، بنجمعهم مع بعض: `g_total[x] = g1[x] - g2[x]`.

### Trick 2: الـ $f(p)$ ثابت (Constant)
*   زي مسألة Count Leaves اللي شوفناها. لو $f(p) = C$ (رقم ثابت).
*   **الحل:** متعملش Phase 1 عشان تحسب الثابت. خلي Phase 1 تحسب "عدد" الأرقام الأولية (يعني افترض إن $f(p) = 1$). 
*   **في Phase 2:** لما تيجي تاخد المجموع من الـ `g`، ابقى اضرب الـ (عدد) اللي طلعلك في الثابت $C$. ده بيوفر وقت وبيمنع الـ Overflow.

### Trick 3: التعامل مع الـ $\lfloor N/i \rfloor$
*   الـ Min-25 معتمد على إن الـ States بتاعتنا كلها عبارة عن $x = \lfloor N/i \rfloor$. 
*   لأن الأرقام دي كبيرة جداً إننا نحطها في Array Index، بنستخدم 2 Arrays للـ Mapping: 
    *   `id1[x]` لو الـ $x \le \sqrt{N}$
    *   `id2[N/x]` لو الـ $x > \sqrt{N}$
*   دايماً استدعي `get_id(x)` عشان تجيب مكان الـ $x$ في الـ `g` array.

---

## 5. Min-25 Sieve C++ Template

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 200005; // Make sure this is slightly larger than sqrt(MAX_N)

/* ==============================================================
   USER DEFINED FUNCTIONS
   ============================================================== */

// 1. Evaluate f(p^e) for Phase 2
ll f_pe(ll p, int e, ll pw) { 
    // Example: if f(x) = x, return pw % MOD;
    // Replace with the logic for f(p^e)
    return pw % MOD; 
}

// 2. Polynomial coefficients for f(p)
// Example: if f(p) = p^2 - p, we have two terms. 
// We will need g1 for p^2 and g2 for p. 
// (The template below is written for a single term f(p) = p^k. Adjust if needed).

/* ============================================================== */

ll primes[N], p_cnt;
ll pref[N]; // Prefix sum of f(p) for primes <= p_cnt

void sieve(int n) {
    vector<bool> is_composite(n + 1, false);
    p_cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!is_composite[i]) {
            primes[++p_cnt] = i;
            // Update prefix sum based on f(p). 
            // Example: if f(p) = p, then pref = pref + i
            // If f(p) = 1, then pref = pref + 1
            ll fp = i % MOD; 
            pref[p_cnt] = (pref[p_cnt - 1] + fp) % MOD; 
        }
        for(int j = 1; j <= p_cnt && primes[j] * i <= n; j++) {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int r, id1[N], id2[N];
ll n_val;

int get_id(ll x) {
    return x <= r ? id1[x] : id2[n_val / x];
}

int tot;
ll g[N]; 
ll a[N];

// Phase 2: Compute the final sum
ll yo(ll x, int j) {
    if (primes[j] >= x) return 0;
    int id = get_id(x);
    
    // Sum of primes > p_j up to x
    ll ans = (g[id] - pref[j] + MOD) % MOD;
    
    // Sum of composites
    for (int i = j + 1; i <= p_cnt && primes[i] * primes[i] <= x; i++) {
        ll pw = primes[i];
        for (int e = 1; pw * primes[i] <= x; e++) {
            ll term1 = (f_pe(primes[i], e, pw) * yo(x / pw, i)) % MOD;
            ll term2 = f_pe(primes[i], e + 1, pw * primes[i]) % MOD;
            ans = (ans + term1 + term2) % MOD;
            pw *= primes[i];
        }
    }
    return ans;
}

ll solve(ll _n) {
    if (_n <= 1) return 0; // Or whatever f(1) is, handle edge cases
    n_val = _n;
    r = sqrt(n_val);
    while (1LL * r * r < n_val) ++r;
    while (1LL * r * r > n_val) --r;
    
    sieve(r);
    tot = 0;
    
    // Phase 1.1: Initialize states
    for (ll i = 1, j; i <= n_val; i = j + 1) {
        ll x = n_val / i;
        j = n_val / x;
        a[++tot] = x;

        // Initialize g[tot] with sum of f(i) from 2 to x treating all as primes.
        // Example for f(p) = p: sum(2...x) = (x*(x+1)/2) - 1
        ll x_mod = x % MOD;
        ll sum_x = (x_mod * (x_mod + 1)) % MOD;
        sum_x = (sum_x * 500000004LL) % MOD; // modulo inverse of 2
        g[tot] = (sum_x - 1 + MOD) % MOD; 

        if (x <= r) id1[x] = tot;
        else id2[n_val / x] = tot;
    }

    // Phase 1.2: DP Transitions (Sieve out composites)
    for (int i = 1; i <= p_cnt; i++) {
        ll sq = primes[i] * primes[i];
        ll p_val = primes[i] % MOD; // This is f(primes[i])
        
        for (int j = 1; j <= tot && sq <= a[j]; j++) {
            int id = get_id(a[j] / primes[i]);
            ll removed = (g[id] - pref[i - 1] + MOD) % MOD;
            removed = (removed * p_val) % MOD;
            g[j] = (g[j] - removed + MOD) % MOD;
        }
    }
    
    // Add f(1) which is usually 1
    return (yo(n_val, 0) + 1) % MOD; 
}
