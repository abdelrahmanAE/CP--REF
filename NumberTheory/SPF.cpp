const int N = 1e6 + 10;
vector<int> spf(N, -1);

void sieve() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == -1) {
            spf[i] = i;
            for (ll j = 1ll * i * i; j < N; j += i) if (spf[j] == -1) spf[j] = i;
        }
    }
}
