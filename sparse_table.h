template<class T> 
struct RMQ{
    int n, logn;
    vector<vector<int>> b;
    vector<T> A;
    void build(const vector<T> &a) {
        A = a, n = sz(a);
        logn = 32 - __builtin_clz(n);
        b.resize(logn, vi(n));
        iota(all(b[0]), 0);
        for(int i = 1; i < logn ; i++){
            for(int j = 0; j < n ; j++){
                b[i][j] = b[i - 1][j];
                if(j + (1 << (i - 1)) < n && A[b[i - 1][j + (1 << (i - 1))]] < A[b[i][j]]) 
                    b[i][j] = b[i - 1][j + (1 << (i - 1))];
            }
        }
    }
    int rangeMin(int x, int y){
        int k = 31 - __builtin_clz(y - x + 1);
        return min(A[b[k][x]], A[b[k][y - (1 << k) + 1]]);
    }
    int minIndx(int x, int y){
        int k = 31 - __builtin_clz(y - x + 1);
        return A[b[k][x]] < A[b[k][y - (1 << k) + 1]] ? b[k][x] : b[k][y - (1 << k) + 1];
    }
};