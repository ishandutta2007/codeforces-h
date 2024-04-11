    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
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
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
/// My Code -------------------------------------------------

int n, m, x, a[maxn], p[maxn], cnt, lazy[maxn];
set<pair<ii,ii>> edges[maxn];
vector<pair<ii,ii>> res;
vector<int> ans;
priority_queue<pair<ii,ii>> q;
priority_queue<ii> gq;

int find_(int x){
    return ( p[x] == x ) ? ( x ) : ( p[x] = find_( p[x] ) );
}

int union_(int u,int v){
    u = find_(u), v = find_(v);
    if( u == v ) return false;
    if( a[u] + a[v] < x ) return false;
    if( edges[u].size() < edges[v].size() ) swap( u , v );
    for( auto i : edges[v] ){
        edges[u].insert({{i.f.f+lazy[v]-lazy[u]-a[v]+a[u],i.f.s},{i.s.f,i.s.s}});
    }
    a[u] += a[v];
    a[u] -= x;
    p[v] = u;
    return true;
}

int try_(int u){
    u = find_(u);
    //if( u != find_(u) ) return false;
    int tmp = a[u];
    if( edges[u].empty() ) return false;
    auto x = *edges[u].rbegin();
    int curr = union_(x.s.f,x.s.s);
    if( curr ) ans.pb(x.f.s);
    edges[u].erase(x);
    lazy[u] += a[u] - tmp;
    if( !edges[u].empty() ){
        gq.push({(*edges[u].rbegin()).f.f+lazy[u],u});
    }
    return curr;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n >> m >> x;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        p[i] = i;
    }

    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v;
        w = a[u] + a[v];
        edges[u].insert({{w,i},{u,v}});
        edges[v].insert({{w,i},{u,v}});
        res.pb({{w,i},{u,v}});
    }
    for(int i=1; i<=n; i++){
        if( !edges[i].empty() )
            gq.push({(*edges[i].rbegin()).f.f,i});
    }

    int tie = 0;
    while( cnt < n - 1 && !gq.empty() ){
        ii tmp = gq.top();
        gq.pop();
        cnt += try_(tmp.s);
        tie ++;
    }

    while( cnt < n - 1 ){
        vector<pair<ii,ii>> nres;
        set<int> tt;
        for( auto i : res ){
            int u = find_(i.s.f), v = find_(i.s.s);
            if( find_(i.s.f) != find_(i.s.s) ){
                edges[u].insert({{a[u]+a[v],i.f.s},{u,v}});
                edges[v].insert({{a[u]+a[v],i.f.s},{u,v}});
                nres.pb({{a[u]+a[v],i.f.s},{u,v}});
                lazy[u] = 0;
                lazy[v] = 0;
                tt.insert(u);
                tt.insert(v);
            }
        }


        for(auto i : tt){
            if( !edges[i].empty() )
                gq.push({(*edges[i].rbegin()).f.f,i});
        }

        int tie = 0;
        while( cnt < n - 1 && !gq.empty() ){
            ii tmp = gq.top();
            gq.pop();
            int thus = try_(tmp.s);
            cnt += thus;
            tie += thus;
        }
        if( tie == 0 ) break;
        nres = res;
    }


    if( cnt == n - 1 ){
        cout << "YES\n";
        for( auto i : ans )
            cout << i << '\n';
        cout << '\n';
    }
    else
        cout << "NO\n";

    return 0;
}