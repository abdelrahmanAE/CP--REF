const int N = 1e5 + 7;
vector<int> ans;
void seive() {
    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (prime[i]) ans.push_back(i * i);
    }
}
to get a number with 3 divisors l7d n 
int choices = upper_bound(ans.begin(), ans.end(), n) - ans.begin();
