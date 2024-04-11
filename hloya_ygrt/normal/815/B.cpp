// hloya template v25
  
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
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out2.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
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
  
template<typename T>
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 2e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
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
    

int a[maxn], fact[maxn];
int tmp[maxn];

int c_nk(int n, int k) {
    int ans = 1ll * fact[k] * binpow<ll>(fact[n], base - 2) % base;
    ans = 1ll * ans * binpow<ll>(fact[k - n], base - 2) % base;
    return ans;
}

void add(int& x, int y) {
    x += y;
    if (x >= base)
        x -= base;
}

int main() {
    // files1;

    int n;
    read(n);

    for (int i = 0; i < n; i++)
        read(a[i]);

    
    if (n == 1)
        return cout << a[0], 0;

    if (n % 2) {
        for (int i = 0; i + 1 < n; i += 2) {
            tmp[i] = a[i] + a[i + 1];
            if (tmp[i] >= base)
                tmp[i] -= base;
            tmp[i + 1] = a[i + 1] - a[i + 2];
            if (tmp[i + 1] < 0)
                tmp[i + 1] += base;
        }
        n--;
        for (int i = 0; i < n; i++)
            a[i] = tmp[i];
    }

    fact[0] = 1;
    for (int i = 1; i < maxn; i++)
        fact[i] = 1ll * fact[i - 1] * i % base;

    int cnt = n / 2 - 1;
    int koef1 = 0;
    for (int i = 0; i < n; i += 2)
        add(koef1, 1ll * a[i] * c_nk(i/2, cnt) % base);

    int koef2 = 0;
    for (int i = 1; i < n; i += 2)
        add(koef2, 1ll * a[i] * c_nk((i-1)/2, cnt) % base);
    
    if (cnt % 2)
        return cout << (koef1 - koef2 + base) % base, 0;
    cout << (koef1 + koef2) % base;
    return 0;
}