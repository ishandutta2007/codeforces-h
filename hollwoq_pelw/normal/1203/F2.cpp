/*
 /+===================================================+\
//+---------------------------------------------------+\
|.|\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\+---------------------------------------------------+//
 \+===================================================+/
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
// I/O
#define setpre(n)           fixed << setprecision(n)
#define Ptest(x)            return cout << x << endl, (void) 0;
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
void debug(){
    cout << endl;
}
template <typename H, typename... T>
void debug(H a, T... b){
    cout << a << ' ';
    debug(b...);
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

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out");
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    return 0;
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[1];
const int MAXN = 1e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

vector<pii> add, sub;
vector<int> keep;

int dp[101][30003], n, r;

void Hollwo_Pelw() {
	cin >> n >> r;
	for (int i = 1, a, b; i <= n; i++){
		cin >> a >> b;
		if (b > 0) add.pb({a, b});
		if (b == 0) keep.pb(a);
		if (b < 0) sub.pb({a, b});
	}
	int ans = 0;
	sort(all(add));
	for (auto vp : add) {
		if (r >= vp.F) r += vp.S, ans ++;
	}
	sort(all(keep));
	for (auto vp : keep) {
		if (r >= vp) ans ++;
	}
	// cout << ans << endl;
	n = sub.size();
	sort(all(sub), [&](const pii & a, const pii & b){
		return a.F + a.S > b.F + b.S;
	});
	dp[0][r] = ans;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= r; j++){
			if (sub[i].F <= j && j + sub[i].S >= 0)
				dp[i + 1][j + sub[i].S] = max(dp[i + 1][j + sub[i].S], dp[i][j] + 1);
			dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
		}
	}
	for (int i = 0; i <= r; i++){
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
}

/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\
+====================== INP ======================+



+====================== OUT ======================+



+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/