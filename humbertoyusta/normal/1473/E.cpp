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

int tc, d[maxn], n, m;
vector<ii> g[maxn];
pair<ii,int> edge[maxn];
priority_queue<ii> q;

int encode(int nod,int st){
    return nod * 4 + st;
}

ii decode(int x){
    return (ii){ x / 4 , x % 4 };
}

void dijkstra(int start){
    d[start] = 0;
    q.push({0,start});
    while( !q.empty() ){
        int u = q.top().s;
        if( -q.top().f > d[u] ){
            q.pop();
            continue;
        }
        q.pop();
        for( auto v : g[u] ){
            if( d[v.f] > d[u] + v.s ){
                d[v.f] = d[u] + v.s;
                q.push({-d[v.f],v.f});
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        for(int j=0; j<=3; j++){
            g[encode(u,j)].pb({encode(v,j),w});
            g[encode(v,j)].pb({encode(u,j),w});
        }

        g[encode(u,0)].pb({encode(v,1),2*w});
        g[encode(v,0)].pb({encode(u,1),2*w});
        g[encode(u,2)].pb({encode(v,3),2*w});
        g[encode(v,2)].pb({encode(u,3),2*w});

        g[encode(u,0)].pb({encode(v,2),0});
        g[encode(v,0)].pb({encode(u,2),0});
        g[encode(u,1)].pb({encode(v,3),0});
        g[encode(v,1)].pb({encode(u,3),0});

        g[encode(u,0)].pb({encode(v,3),w});
        g[encode(v,0)].pb({encode(u,3),w});
    }

    for(int i=0; i<maxn; i++)
        d[i] = INF;

    dijkstra(encode(1,0));

    for(int i=2; i<=n; i++)
        cout << d[encode(i,3)] << ' ';

    return 0;
}