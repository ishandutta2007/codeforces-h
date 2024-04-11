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
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
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

int tc, st[maxn], q, n, lazy[maxn];
ii Q[maxn];
string s, t;

void lazyp(int nod,int l,int r){
    st[nod] = lazy[nod] * ( r - l + 1 );
    if( l != r ){
        lazy[2*nod] = lazy[nod];
        lazy[2*nod+1] = lazy[nod];
    }
    lazy[nod] = -1;
}

void build(int nod,int l,int r){
    lazy[nod] = -1;
    if( l == r ){
        st[nod] = ( t[l-1] == '1' );
        return;
    }
    int mi = ( l + r ) >> 1;
        build(2*nod,l,mi);
        build(2*nod+1,mi+1,r);
    st[nod] = st[2*nod] + st[2*nod+1];
}

void update(int nod,int l,int r,int x,int y,int val){
    if( lazy[nod] != -1 ) lazyp(nod,l,r);
    if( l > y || r < x ) return;
    if( l >= x && r <= y ){
        lazy[nod] = val;
        lazyp(nod,l,r);
        return;
    }
    int mi = ( l + r ) >> 1;
        update(2*nod,l,mi,x,y,val);
        update(2*nod+1,mi+1,r,x,y,val);
    st[nod] = st[2*nod] + st[2*nod+1];
}

int query(int nod,int l,int r,int x,int y){
    if( lazy[nod] != -1 ) lazyp(nod,l,r);
    if( l > y || r < x ) return 0;
    if( l >= x && r <= y ){
        return st[nod];
    }
    int mi = ( l + r ) >> 1;
    return query(2*nod,l,mi,x,y) + query(2*nod+1,mi+1,r,x,y);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc -- ){

        cin >> n >> q;

        cin >> s >> t;

        build(1,1,n);

        bool can = 1;

        for(int i=1; i<=q; i++)
            cin >> Q[i].f >> Q[i].s;

        for(int i=q; i>=1; i--){
            int u, v;
            u = Q[i].f, v = Q[i].s;
            int sum = query(1,1,n,u,v);
            if( sum < ( v - u + 1 + 1 ) / 2 ){
                update(1,1,n,u,v,0);
                continue;
            }
            if( sum > ( v - u + 1 ) / 2 ){
                update(1,1,n,u,v,1);
                continue;
            }
            can = 0;
        }

        for(int i=1; i<=n; i++){
            if( query(1,1,n,i,i) != ( s[i-1] == '1' ) )
                can = 0;
        }

        if( can ) cout << "YES\n";
            else cout << "NO\n";
    }

    return 0;
}