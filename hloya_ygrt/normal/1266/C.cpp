#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
 
// hloya template v26
 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
 
#include <bits/stdc++.h>
using namespace std;
 
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))
 
#define ull unsigned long long
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
 
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
 
// #define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
 
void bad(string mes = "NO"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
 
template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}
 
mt19937_64 mt_rand(
    chrono::system_clock::now().time_since_epoch().count()
);
 
template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }
 
// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
  
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
  
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}
 
template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
 
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e5 + 3, base = 998244353;
const ll llinf = 2e18 + 5;
 
int binpow(int a, int s) { 
    int res = 1;
    while (s) {
        if (s % 2) {
            res = 1ll * res * a % base;
        }
        a = 1ll * a * a % base;
        s /= 2;
    }
    return res;
}

int a[599][599];


int main() {
// 	files1;
	fast_io;

    int r, c;
    cin >> r >> c;

    if (r == 1 && c == 1) {
        cout << 0;
        return 0;
    }
    if (r == 1) {
        for (int i = 0; i < c; i++) {
            cout << 2 + i << ' ';
        }
        return 0;
    }
    if (c == 1) {
        for (int i = 0; i < r; i++) {
            cout << 2 + i << '\n';
        }
        return 0;   
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int x = (c + 1 + i) * (j + 1);
            // if (i == 0) {
            //     cout << (gcd(x, x + j + 1) == (j + 1)) << endl;
            // }
            cout << x << ' ';
            a[i][j] = x;
        }
        cout << endl ;
    }
    return 0;

    set<int> s;
    for (int i = 0; i < r; i++) {
        int g = 0;
        for (int j = 0; j < c; j++) {
            g = gcd(a[i][j], g);
        }
        s.insert(g);
        // cout << g << endl;
    }
    for (int j = 0; j < c; j++) {
        int g = 0;
        for (int i = 0; i < r; i++) {
            g = gcd(a[i][j], g);
        }
        s.insert(g);
        // cout << g << endl;
    }

    assert(s.size() == r + c);
    // assert(s.end())
}