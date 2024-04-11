#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 2e6 + 10;
const int mod = 998244353;
int f[N], g[N];
int main() {
  int n;
  cin >> n;
  f[1] = 1;
  for(int i = 1; i <= n; i ++)
    for(int j = i; j <= n; j += i)
      g[j] ++;
  rep(i, 2, n) {
    f[i] = (2ll * f[i - 1] + g[i]) % mod;
  }
  printf("%d\n", (f[n] + mod - f[n - 1]) % mod);
  return 0;
}