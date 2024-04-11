#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
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
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int t, n, s[N];
set<int> S;
void dfs(int u) {
  if(u > n) return ;
  if(s[u] > 1) {
    dfs(u + s[u]);
    s[u] --;
    if(s[u] == 1) S.erase(u);
  } else dfs(*S.lower_bound(u));
}
int main() {
  scanf("%d", &t);
  while(t --) {
    scanf("%d", &n);
    S.clear();
    rep(i, 1, n) scanf("%d", s + i);
    rep(i, 1, n) if(s[i] > 1) S.insert(i);
    S.insert(n + 1);
    ll ans = 0;
    rep(i, 1, n) {
      if(s[i] != 1) {
        int t = max(0, s[i] - max(n - i, 1));
        ans += t; s[i] -= t;
        while(s[i] != 1) {
          dfs(i); ans ++;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}