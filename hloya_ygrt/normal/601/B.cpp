#include <bits/stdc++.h>
using namespace std;
 

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
 
#define ll long long
#define ld long double
#define pii pair<int,int>
 
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
 
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
 
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
void read(T& a) {
    a = input<T>();
}
 
template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}
 
template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}
 
template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 1e5 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 1;
 
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

int l[maxn];
int a[maxn];

pair<int, int> st[maxn][20];
void build(int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = mp(l[i], i);
        // cout << l[i] << ' ';
    }
    puts("");
    for (int j = 1; j < 20; j++)
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            // cout << i << ' ' << j << ' ' << st[i][j].f << ' ' << st[i][j].s << endl;
        }
}

int lg[maxn];

pair<int, int> get(int l, int r) {
    int len = r - l + 1;
    int pw = lg[len];
    pair<int, int> res = max(st[l][pw], st[r - (1 << pw) + 1][pw]);
    return res;
}

ll solve(int l, int r) {
    if (l > r)
        return 0;
    pair<int, int> mid = get(l, r);
    
    ll res = 0;
    res += 1LL * (r - mid.s + 1) * (mid.s - l + 1) * mid.f;
    return res + solve(l, mid.s - 1) + solve(mid.s + 1, r);
}

int main() {
    int n, q;
    read(n, q);
    for (int i = 0; i < n; i++)
        read(a[i]);
    for (int i = 0; i + 1 < n; i++) {
        l[i] = abs(a[i + 1] - a[i]);
    }
    build(n - 1);

    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;

    for (int i = 0; i < q; i++) {
        int l, r;
        read(l, r);
        l--, r--;
        cout << solve(l, r - 1) << endl;
    }
    return 0;
}