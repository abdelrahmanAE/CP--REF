vector<int> getMultiples(int x, int n){
    vector<int>ret;
    for(int i = x; i < n; i+=x){
            ret.push_back(i);
    }
    return ret;
}
