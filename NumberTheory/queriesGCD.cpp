Given a sequence of integers a1, ..., an and q queries x1, ..., xq on it. For each query xi
you have to count the number of pairs (l, r) such that 1 ≤ l ≤ r ≤ n and gcd(al, al + 1, ..., ar) = xi.
is a greatest common divisor of v1, v2, ..., vn, that is equal to a largest positive integer that divides all vi.

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    map<int, int>currGcd, cnt;
    int g  = v[0];
    for (int i = 0; i < n; i++) {
        map<int, int>nxt;
        nxt[v[i]]++;
        for (auto &[it1,it2] : currGcd) {
            int res = gcd(it1, v[i]);
            nxt[res] += it2;
        }
        for (auto &[it1, it2] : nxt) cnt[it1] += it2;
        currGcd = move(nxt);
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << cnt[x] << Endl
    }
}
