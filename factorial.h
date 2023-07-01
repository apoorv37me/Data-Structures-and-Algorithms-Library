vm fct(maxn, 1), invf(maxn, 1);
void calc_fact() {
    for(int i = 1 ; i < maxn ; i++) {
        fct[i] = fct[i - 1] * i;
        invf[i] = mi(1) / fct[i];
    }
}
mi C(int n, int r) {
    if(r > n)   return mi(0);
    return fct[n] * invf[r] * invf[n - r];
}