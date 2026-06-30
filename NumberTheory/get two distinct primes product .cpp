const int N = 6000000 + 5;
vector<int> ans;
void seive() {
    vector<bool> prime(N + 1, true);
    vector<int> p;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            p.push_back(i);
        }
    }
    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size(); j++) {
            if (p[i] * p[j] < 10900000)  ans.push_back(p[i] * p[j]);
            else  break;
        }
    }
    sort(ans.begin(), ans.end());
}
void solve() {
    int n; cin >> n;
    cout << ans[n - 1] << Endl
}
