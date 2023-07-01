/*   coded by apoorv_me   */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using minheap = priority_queue<T,vector<T>,greater<T> >; 

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
#define pii pair<int, int>
#define vi vector < int >
#define vpi vector <pair <int , int > >
#define pll pair<ll, ll>
#define vl vector < ll >
#define vpl vector <pair <ll , ll > >
#define vb vector<bool>

#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define setbit(x) __builtin_popcountll((ll)x)
#define b_ctz(x)   __builtin_ctzll(ll(x))
#define log_2(x)    63 - __builtin_clzll(ll(x))
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)((a).size()))
#define bs binary_search

//random generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a,ll b){if(a > b){return -1;}return a + (ll)rng() % (b - a + 1);}

// Input Operatirons Pair, Vector
template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a){in >> a.F >> a.S;return in;}
template<class T>istream& operator>>(istream &in, vector<T> &a){for(auto &i: a){in >> i;} return in;}

// Output Operations Pair Vector
template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a){os << a.F << " " << a.S;return os;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a){for(int i = 0 ; i < sz(a) ; i++){if(i != 0){os << ' ';}os << a[i];}return os;}

#ifdef APOORV
#include "debug.h"
#else
#define dbg(...) "11-111"
#endif

const ll INF = 4e18;
// const ll mod = 1000000007;
// const ll mod = 998244353;
const int maxn = 200005;

namespace generater{
    //random generator
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    long long rnd(long long a, long long b){if(a > b){return -1;}return a + rng() % (b - a + 1);}

    struct DSU {
        int n, cmps;
        vector<int> p, sub, cnt;
        DSU () {}
        DSU(int n_) : n(n_), cmps(n_) {
            p.resize(n+1);
            sub.resize(n+1, 1);
            cnt.resize(n + 1, 1);
            iota(p.begin(), p.end(), 0);
        }
        int parent(int i) {
            assert(i <= n);
            return p[i] = (p[i] == i ? i : parent(p[i]));
        }
        bool join(int x, int y) {
            assert(x <= n && y <= n);
            x = parent(x), y = parent(y);
            if(x == y) {
                return false;
            }
            --cmps;
            if(sub[x] > sub[y]) {
                swap(x, y);
            }
            sub[y] += sub[x];
            cnt[y] += cnt[x];
            cnt[x] = 0;
            p[x] = y;
            return true;
        }
    };


    void generate_graph(int n, int m, bool con) {
        ordered_set<pii> os;
        DSU b(n);
        for(int i = 1 ; i <= n ; i++) {
            for(int j = i + 1 ; j <= n ; j++) {
                os.insert({i, j});
            }
        }
        while(m) {
            assert(!os.empty());
            int p = rnd(0, sz(os) - 1);
            auto [u, v] = *os.find_by_order(p);
            if(b.cmps == m + 1 && con) {
                if(b.join(u, v)) {
                    cout << u << " " << v << nl;
                    m--;
                }
            } else {
                m--;
                cout << u << " " << v << nl;
                b.join(u, v);
            }
            os.erase(mp(u, v));
        }
    }
}

int32_t main() {
    int t = rnd(1, 1);
    // cout << t << endl;
    while(t--){
        int n = rnd(1, 10000);
        cout << n << " " << rnd(1, 10000) << nl;
    }
    return 0;
}
