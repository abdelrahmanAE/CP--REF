const int N=1e6+6;
bool isPrime[N];
vector<int> primes

void sieve(){ 
    fill(isPrime, isPrime+N, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i < N; i++){
		if(isPrime[i]){
        primes.push_back(i);
            for(int m = i*i; m < N; m += i){
                isPrime[m] = false;
            }
		    }
    }
}
