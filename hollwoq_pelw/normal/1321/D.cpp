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
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
bool endline = false;
template<class T>
istream& operator >> (istream& inp, vector<T>& v){
    for (auto& it : v) inp >> it;
    return inp;
}
template<class T>
ostream& operator << (ostream& out, vector<T>& v){
    for (auto& it : v) out << it << (endline ? "\n" : " ");
    return out;
}
template<class T, class U>
istream& operator >> (istream& inp, pair<T, U>& v){
    inp >> v.F >> v.S;
    return inp;
}
template<class T, class U>
ostream& operator << (ostream& out, pair<T, U>& v){
    out << v.F << ' ' << v.S;
    return out;
}

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
const int MAXN = 1e6 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
//#define int long long

vector<int> radj[MAXM], adj[MAXM];
int mn, mx, n, m, k, path[MAXM], d[MAXM];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void Solve(){
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        radj[v].pb(u);
        adj[u].pb(v);
    }
    cin >> k;
    for (int i = 1; i <= k; i++){
        cin >> path[i];
    }
    for (int i = 1; i <= n; i++){
        d[i] = 2e9;
    }
    pq.push({d[path[k]] = 0, path[k]});
    while(pq.size()){
        int u = pq.top().S; pq.pop();
        for (auto v : radj[u]){
            if (d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                pq.push({d[v], v});
            }
        }
    }
    //for (int i = 1; i <= n; i++) cout << d[i] << ' '; cout << endl;
    for (int i = 2; i <= k; i++){
        int u = path[i-1], v = path[i];
        if (d[u] != d[v] + 1)
            mn++, mx++;
        else{
            for (auto p : adj[u]){
                if (p != v && d[p] == d[v]){
                    mx ++;
                    break;
                }
            }
        }
    }
    cout << mn << ' ' << mx;
}


signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+===+===+===+===+===+== INP ==+===+===+===+===+===+


+===+===+===+===+===+== OUT ==+===+===+===+===+===+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/