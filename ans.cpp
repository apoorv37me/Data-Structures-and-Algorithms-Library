#define TESTCASE
#ifndef LOCAL
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// pbds = find_by_value(), order_of_key()
template<class T> using minheap = priority_queue<T,vector<T>,greater<T> >; 
template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
#define nl "\n"
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) ((int)((a).size()))

//random generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a,ll b){if(a > b){return -1;}return a + (ll)rng() % (b - a + 1);}

#ifdef LOCAL
#include "../debug.h"
#else
#define dbg(...) "11-111"
#endif

const ll Inf = 4e18;
// const int mod = 1000000007;
// const int mod = 998244353;
const int maxn = 1000005;
/*----------------------------------x---Code-Below---x--------------------------------*/

void __solve_testcase(int test_case);
void pre_process();

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre_process();

    int no_of_testcase = 1;
#ifdef TESTCASE
    cin >> no_of_testcase;
#endif
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        // cout << "Case #" << testcase << ": ";
        __solve_testcase(testcase);
    }
    return 0;
}

void pre_process() {

}
void __solve_testcase(int test_case) {

}

