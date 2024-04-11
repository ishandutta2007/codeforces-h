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
//const int mod1 = 998244353, mod = 1e9 + 7;
//const int MAXN = 1e5 + 6 , MAXM = 1e4 + 5;
//const int inf = 2e9; const ll linf = 1e18;
// code
//#define int long long

const int chk[] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
int n, k, a[2020], ans[2020];
bool ok[2020][2020];

void get_ans(int x, int p){
    if (x > k || ok[x][p]) return;
    ok[x][p] = 1;
    if (p == n){
        if (x == k){
            for (int i = 0; i < n; i++) cout << ans[i]; exit(0);
        }
        return;
    }
    for (int i = 9; i >= 0; i--) if ((chk[i] & a[p]) == a[p]){
        ans[p] = i; get_ans(x + __builtin_popcount(chk[i] ^ a[p]), p + 1);
    }
}

void Solve () {
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < 7; j++)
            a[i] = a[i] * 2 + (s[j] - '0');
    }
    get_ans(0, 0);
    cout << -1 << endl;
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