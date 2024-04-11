#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 2;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}


bool t[5000000];
int a[5000000];
int memo[5000000];
void solve() {
	int n, m; cin >> n >> m;
	ll seed = 0;
	ll base = 0;
	auto rn = [&]()->ll {
		ll res = seed;
		seed = (seed * base + 233) % mod;
		return res;
	};
	int cur = 0;
	vector<int> p(m), k(m), b(m), w(m);
	rep(i, m)cin >> p[i] >> k[i] >> b[i] >> w[i];
	rep(i, m) {
		seed = b[i];
		base = w[i];
		for (int j = cur; j < p[i]; j++) {
			t[j] = (rn() % 2);
			a[j] = (rn() % k[i]) + 1;
			memo[j] = a[j];
		}
		cur = p[i];
	}
	ll s[2] = {};
	rep(i, n) {
		s[t[i]] += a[i];
	}
	int col = t[0];
	int loc = 0;
	if (s[col] > s[col ^ 1]) {
		a[0]--;
		if (s[loc ^ 1] == 0) {
			modint ans = 1;
			rep(i, n) {
				modint val = (memo[i] - a[i]) ^ ((ll)(i + 1) * (i + 1));
				val += 1;
				ans *= val;
			}
			cout << ans << "\n"; return;
		}
		for (int j = 1; j < n; j++)if (t[j] != col) {
			loc = j; break;
		}
	}
	col = t[loc];
	ll cnt = 0;
	for (int j = 0; j < 2 * n; j++) {
		int id = (loc + j) % n;
		if (t[id] == col) {
			cnt += a[id]; a[id] = 0;
		}
		else {
			ll mi = min((ll)a[id], cnt);
			a[id] -= mi;
			cnt -= mi;
		}
	}
	modint ans = 1;
	rep(i, n) {
		modint val = (ll)(memo[i]-a[i]) ^ ((ll)(i+1) * (i+1));
		val += 1;
		ans *= val;
	}
	//rep(i, n)cout << memo[i]-a[i] << "\n";
	cout << ans << "\n"; return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}