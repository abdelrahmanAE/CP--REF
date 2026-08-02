count how many subarrays sum equal to k

void solve() {
    int n, s; cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    map<int,int> mp;
    mp[0] = 1;
    int curr = 0, cnt = 0;
    for (int num : v) {
        curr += num;
        if (mp.find(curr - s) != mp.end()) {
            cnt += mp[curr - s];
        }
        mp[curr]++;
    }
    cout << cnt << Endl

}
