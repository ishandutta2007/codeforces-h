    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
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
const int maxn = 400010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
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
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, m, p[maxn], d[maxn], st, id[maxn];
vector<int> g[maxn];
bool ctie = 0;
vector<int> ans, tp;

void dfs(int u){
    for( auto v : g[u] ){
        if( !p[v] ){
            p[v] = u;
            dfs(v);
        }
        else{
            ctie = 1;
        }
    }
    tp.pb(u);
    id[u] = tp.size();
}

void backtrack(int u, int v){
    if( p[u] == u ){
        if( u <= n ) cout << u;
            else cout << u - n;
        if( u == v ) cout << '\n';
            else cout << ' ';
        return;
    }
    backtrack(p[u],v);
    if( u <= n ) cout << u;
        else cout << u - n;
    if( u == v ) cout << '\n';
        else cout << ' ';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> d[i];
        for(int j=1; j<=d[i]; j++){
            int u;
            cin >> u;
            g[i].pb(n+u);
            g[n+i].pb(u);
        }
    }

    cin >> st;

    p[st] = st;
    dfs(st);

    for(int i=1; i<=n; i++){
        if( d[i] == 0 && p[n+i] != 0 ){
            cout << "Win\n";
            backtrack(n+i,n+i);
            return 0;
        }
    }

    //for(auto i:tp)db(i)
    for(int i=1; i<=n*2; i++){
        for( auto j : g[i] ){
            if( id[i] && id[j] ){
                if( id[i] < id[j] ){
                    cout << "Draw\n";
                    return 0;
                }
            }
        }
    }

    cout << "Lose\n";

    return 0;
}