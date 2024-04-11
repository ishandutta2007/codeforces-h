/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 5e5 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
//#define int long long
#define endl '\n'
int pos[2*MAXN], n, x = 0;
vector<int> adj[MAXN], ans[MAXN];

void dfs(int u, int p){
    for (int v : adj[u]) if (p != v) pos[++x] = v;
    pos[++x] = u;
    reverse(all(adj[u]));
    for (int v : adj[u]){
        if (p != v)
            dfs(v, u);
    }
}

void Solve() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    pos[++x] = 1;
    dfs(1, -1);
    for (int i = 1; i <= 2 * n; i++){
        ans[pos[i]].eb(i);
    }
    cout << endl;
    for (int i = 1; i <= n; i++){
        for (auto v:ans[i]) 
            cout << v << ' ';
        cout << endl;
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    // cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/