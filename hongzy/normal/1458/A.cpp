#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
 
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
// mt19937_64 
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
 
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, m;
ll a[N], b[N];
ll gcd(ll x, ll y) {
   return y == 0 ? x : gcd(y, x % y);
}
int main() {
   scanf("%d%d", &n, &m);
   rep(i, 1, n) scanf("%lld", a + i);
   rep(i, 1, m) scanf("%lld", b + i);
   ll g = 0;
   rep(i, 2, n) g = gcd(g, abs(a[1] - a[i]));
   rep(i, 1, m) printf("%lld ", gcd(g, a[1] + b[i]));
   return 0;
}