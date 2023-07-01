vector<bool> Prime(maxn, 1);
// vector<int> spf(maxn);
void sieve(){
    Prime[0] = Prime[1] = 0;
    // iota(all(spf), 0);
    for (int i = 2; i < maxn ; i++) {
        if (Prime[i] && i <= maxn / i) {
            for (int j = i * i; j < maxn ; j += i){
                Prime[j] = 0;
                // spf[j] = min(spf[j], i);
            }
        }
    }
}