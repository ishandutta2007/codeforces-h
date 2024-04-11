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

int a[maxn];

map<int, ll> out[maxn];
map<int, ll> in[maxn];

int main() {
    // files1;
    fast_io;

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll d;
        scanf("%d%d%lld", &u, &v, &d);

        out[u][v] += d;
        in[v][u] += d;
    }

    for (int i = 1; i <= n; i++) {
        while (true) {
            if (in[i].empty() || out[i].empty()) {
                break;
            }       
            auto a = *(--in[i].end());
            auto b = *(--out[i].end());
            
            if (a.s == 0) {
                in[i].erase(--in[i].end());
                continue;
            }
            if (b.s == 0) {
                out[i].erase(--out[i].end());
                continue;
            }

            ll mn = min(a.s, b.s);
            int u = a.f, v = b.f;
            
            in[i][u] -= mn;
            out[u][i] -= mn;

            in[v][i] -= mn;
            out[i][v] -= mn;

            out[u][v] += mn;
            in[v][u] += mn;
        }
    }

    vector<tuple<int, int, ll>> ans;
    ans.reserve(300000);
    for (int i = 1; i <= n; i++) {
        for (auto c : out[i]) {
            if (c.s != 0) {
                ans.eb(i, c.f, c.s);
            }
        }
    }
    assert(ans.size() <= 300000);
    printf("%d\n", (int)ans.size());
    for (const auto& [a, b, c] : ans) {
        printf("%d %d %lld\n", a, b, c);
        // cout << a << ' ' << b << ' ' << c << "\n";
    }
}