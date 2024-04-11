// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// hloya template v27

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
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible") {cout << mes;exit(0);}
void bad(int mes) {cout << mes;exit(0);}
  
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

inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
    return count;
}

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
const int maxn = (int)2e5 + 450, base = 1e9 + 7;
const ll llinf = 2e18 + 5;

int a[maxn], t[4 * maxn];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v<<1|1, tm + 1, tr);
    }
}

void push(int v, int tl, int tr) {
    if (t[v] != 0) {
        upmax(t[v<<1], t[v]);
        upmax(t[v<<1|1], t[v]);
        t[v] = 0;
    }
}

void output(int v, int tl, int tr) {
    if (tl == tr) {
        cout << t[v] << ' ';
    } else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        output(v<<1, tl, tm);
        output(v<<1|1, tm + 1, tr);
    }
}

void mod(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tr);
        if (pos <= tm) {
            mod(v<<1, tl, tm, pos, val);
        } else {
            mod(v<<1|1, tm + 1, tr, pos, val);
        }
    }
}

int main() {
    // files1;
    fast_io;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);
    
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int kek;
        cin >> kek;
        if (kek == 1) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            mod(1, 0, n - 1, pos, val);
        } else if (kek == 2) {
            int mda;
            cin >> mda;
            upmax(t[1], mda);
        }
    }

    output(1, 0, n - 1);
    return 0;
}