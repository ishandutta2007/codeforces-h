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

ld dp[101][1001 * 101];
int b[maxn];

ld getSum(int w, int l, int r) {
    if (l > r || r < 0)
        return 0;
    ld res = dp[w][r];
    if (l)
        res -= dp[w][l - 1];
    return res;
}

int main() {
    //files1;
    int n, m, kek = 0;
    read(n, m);
    if (m == 1)
        bad("1");
    for (int i = 1; i <= n; i++) {
        read(b[i]);
        kek += b[i];
    }
    for (int i = 0; i <= n * m; i++)
        dp[0][i] = m - 1;
    for (int p = 1; p <= n; p++) {
        for (int sum = 0; sum <= m * n; sum++) {
            dp[p][sum] += (ld)getSum(p - 1, max(0, sum - m), sum - b[p] - 1) / (m - 1);
            dp[p][sum] += (ld)getSum(p - 1, sum - b[p] + 1, sum - 1) / (m - 1);
        }
        for (int sum = 1; sum <= m * n; sum++)
            dp[p][sum] += dp[p][sum - 1];    
    }

    cout << fixed << setprecision(20) << dp[n][kek - 1] + 1;
    return 0;
}