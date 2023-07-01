void getdepth(vi a[], int i, vi &dpth, vi &par, int d, int p){
    dpth[i] = d;
    par[i] = p;
    for(auto &u: a[i]){
        if(dpth[u] == -1){
            getdepth(a, u, dpth, par, d + 1, i);
        }
    }
}

class blift{
    vector<vi> lift;
    vector<vl> sum;
    vi depth;
    int mx, n;
    public:
    blift(vi &par, int n, vi &dpth){
        depth = dpth;
        mx = log2(n) + 1;
        lift = vector<vi> (mx, vi(n));
        lift[0] = par;
        for(int i = 1; i < mx ; i++){
            for(int j = 0; j < n ; j++){
                if(lift[i - 1][j] == -1){
                    lift[i][j] = lift[i - 1][j];
                    continue;
                }
                lift[i][j] = lift[i - 1][lift[i - 1][j]];
            }
        }
    }
    blift(vi &par, int n, vi &dpth, vl b){
        depth = dpth;
        mx = log2(n) + 1;
        lift = vector<vi> (mx, vi(n));
        sum = vector<vl> (mx, vl(n));
        lift[0] = par;
        sum[0] = b;
        for(int i = 1; i < mx ; i++){
            for(int j = 0; j < n ; j++){
                if(lift[i - 1][j] == -1){
                    lift[i][j] = lift[i - 1][j];
                    sum[i][j] = sum[i - 1][j];
                    continue;
                }
                lift[i][j] = lift[i - 1][lift[i - 1][j]];
                sum[i][j] = sum[i - 1][j] + sum[i - 1][lift[i - 1][j]];
            }
        }
    }
    int kthancestor(int n, int k){
        for(int i = mx - 1 ; i >= 0 ; i--){
            if((1<<i) & k){
                n = lift[i][n];
            }
            if(n == -1)
                return -1;
        }
        return n;
    }

    int lca(int a, int b){
        if(depth[a] < depth[b])
            swap(a, b);
        int mov = depth[a] - depth[b];
        a = kthancestor(a, mov);
        if(a==b)
            return a;
        for(int i = mx - 1 ; i >= 0 ; i--){
            if(lift[i][a]!=lift[i][b]){
                a = lift[i][a];
                b = lift[i][b];
            }
        }
        return lift[0][a];
    }

    int dist(int a, int b){
        int x = lca(a, b);
        return depth[a] + depth[b] - (2*depth[x]);
    }

    ll getSum(int a, int b){
        if(depth[a] < depth[b])
            swap(a, b);
        int mov = depth[a] - depth[b];
        ll res = 0;
        for(int i = mx - 1 ; i >= 0 ; i--){
            if((1<<i) & mov){
                res += sum[i][a];
                a = lift[i][a];
            }
        }
        if(a==b)
            return a;
        for(int i = mx - 1 ; i >= 0 ; i--){
            if(lift[a][i]!=lift[b][i]){
                res += sum[i][a];
                res += sum[i][b];
                a = lift[i][a];
                b = lift[i][b];
            }
        }
        return res + sum[0][a] + sum[0][b];
    }
};