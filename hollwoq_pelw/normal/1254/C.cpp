/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#pragma GCC optimize ("O3")
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
const int MAXN = 5005, MAXM = 2e5 + 5;
// code
#define int long long

int tmp, n;
vector<pii> area;
vector<int> up, dw;

void ask(int type, int a, int b, int c){
    cout << type << ' ' << a << ' ' << b << ' ' << c << endl;
    cin >> tmp;
}

void Solve() {
    cin >> n;
    int id = 2;
    for (int i = 3; i <= n; i++){
        ask(2, 1, i, id);
        if (tmp < 0) id = i;
    }
    for (int i = 2; i <= n; i++){
        if (i == id) continue;
        ask(1, 1, i, id);
        area.eb(tmp, i);
    }
    sort(all(area));
	int top = area.back().S;
	area.pop_back(); dw.eb(id);
	for(int i = 0; i < area.size(); i++){
		ask(2, 1, area[i].S, top);
		if(tmp < 0) dw.eb(area[i].S);
		else up.eb(area[i].S);
	}
	cout << "0 1 ";
	for(int i = 0; i < up.size(); i++) cout << up[i] << ' ';
	cout << top << ' ';
	for(int i = dw.size()-1; i >= 0; i--) cout << dw[i] << ' ';
	cout << endl;
    
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    //cin >> TC;
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