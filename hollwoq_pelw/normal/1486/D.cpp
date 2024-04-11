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

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[0];
const int MAXN = 2e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
const ld eps = 1e-9;
#define int long long

void Hollwo_Pelw() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (auto & v : a)
        cin >> v;

    function<bool(int)> chk = [&](int x) {
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            b[i] = a[i] >= x ? 1 : -1;
        vector<int> pref(n), prefmin(n);
        for (int i = 0; i < n; i++){
            pref[i] = b[i] + (i ? pref[i - 1] : 0);
            prefmin[i] = min(pref[i], (i ? prefmin[i - 1] : 0));
        }
        for (int i = k - 1; i < n; i++){
            if (pref[i] > (i >= k ? prefmin[i - k] : 0))
                return 1;
        }
        return 0;
    };

    int l = 1, r = n, res = 0;
    while (l <= r){
        int m = l + r >> 1;
        if (chk(m)){
            res = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    cout << res;
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