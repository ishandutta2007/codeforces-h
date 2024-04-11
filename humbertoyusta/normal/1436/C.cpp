    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 1010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// rng
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Pow------------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, x, pos, a[maxn], c0, c1, c2, fact[maxn], C[maxn][maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    C[0][0] = 1;
    for(int i=1; i<maxn; i++)
        for(int j=0; j<maxn; j++)
            if( j ) C[i][j] = ( C[i-1][j] + C[i-1][j-1] ) % mod;
                else C[i][j] = C[i-1][j];

    fact[0] = 1;
    for(int i=1; i<maxn; i++)
        fact[i] = fact[i-1] * i % mod;

    int tc = 1;
    while( tc -- ){
        cin >> n >> x >> pos;
        int l = 0, r = n;
        c0 = c1 = c2 = 0;
        while( l < r ){
            int mi = ( l + r ) >> 1;
            if( mi < pos ){ a[mi] = -1; c0 ++; }
            if( mi > pos ){ a[mi] = 1; c1 ++; }
            if( mi == pos ){ a[mi] = 2; c2 ++; }
            if( mi <= pos ) l = mi + 1;
                else r = mi;
        }
        if( c0 > x-1 ){ cout << 0 << '\n'; continue; }
        if( c1 > n-x ){ cout << 0 << '\n'; continue; }
        cout << ( C[x-1][c0] * fact[c0] % mod ) * ( C[n-x][c1] * fact[c1] % mod ) % mod * fact[n-c0-c1-1] % mod << '\n';
    }

    return 0;
}