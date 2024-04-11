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
const int mod1 = 998244353, mod = 1e9+7, INF = 2e9;
const int MAXN = 100005, MAXM = 200010;
// code
#define int long long

int P[4020], cnt[4020];

int find(int a){
    return a == P[a] ? a:find(P[a]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (x > y) swap(x, y);
    P[y] = x;
    cnt[x] += cnt[y];
    cnt[y] = 0;
}

void Solve (){
    int n; cin >> n;
    for (int i = 1; i <= 2*n; i++){
        P[i] = i; cnt[i] = 1;
    }
    int mx = 0;
    for (int i = 1, x; i <= 2*n; i++){
        cin >> x;
        if (x > mx)
            mx = x;
        join(mx, x);
    }
    vector<int> arr;
    for (int i = 1; i <= 2*n; i++){
        if (P[i] == i) arr.pb(cnt[i]);
    }
//    for (auto v:arr) cout << v << ' '; cout << endl;
    vector<vector<int>> dp(n + 1, vector<int> (arr.size() + 1, 0));
    sort(all(arr));
    dp[0][0] = 1;
    for (int j = 0; j < arr.size(); j++){
        for (int i = 0; i <= n; i++){
            dp[i][j+1] = dp[i][j] || (i >= arr[j] && dp[i - arr[j]][j]);
        }
    }
    cout << (dp[n][arr.size()] ? "YES\n" : "NO\n");
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO;
    int TC = 1;
    cin >> TC;
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