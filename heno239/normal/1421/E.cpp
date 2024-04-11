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
constexpr ll mod = 998244353;
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if(abs(x)>=m)x %= m;
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

vector<string> s[11];
void expr() {
	s[1] = { "1" };
	Rep1(i,2, 10) {
		for (int j = 1; j < i; j++) {
			for (string t : s[j])for (string u : s[i - j]) {
				string ad = t + u;
				rep(k, ad.size())ad[k] = '0' + '1' - ad[k];
				s[i].push_back(ad);
			}
		}
		sort(all(s[i]));
		s[i].erase(unique(all(s[i])), s[i].end());
	}
	rep1(i, 8) {
		cout << i << " start " << "\n";
		for (string t : s[i])cout << t << "\n";
	}
}
void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	if (n == 1) {
		cout << a[0] << "\n"; return;
	}
	if (n % 2 == 0) {
		sort(all(a));
		vector<ll> ra(n + 1);
		rep(i, n)ra[i + 1] = ra[i] + a[i];
		int c = (n / 2) % 3; c = (c + 2) % 3;
		ll ans = -INF;
		for (int x = c; x <= n; x+=3) {
			ll sum = ra[n] - ra[n - x] - (ra[n - x]);
			ans = max(ans, sum);
		}
		cout << ans << "\n";
	}
	else {
		vector<LP> v(n);
		rep(i, n)v[i] = { a[i],i };
		sort(all(v));
		vector<ll> ra(n + 1);
		rep(i, n) {
			ra[i + 1] = ra[i] + v[i].first;
		}
		int c = (n + 1) / 2; c %= 3;
		ll ans = -INF;
		for (int x = c; x <= n; x += 3) {
			if (x == (n + 1) / 2) {
				bool valid = false;
				rep(j, x) {
					if (v[n - 1 - j].second % 2)valid = true;
				}
				if (valid) {
					ll sum = ra[n] - ra[n - x] - (ra[n - x]);
					ans = max(ans, sum);
				}
				else {
					ll sum = ra[n] - ra[n - x] - (ra[n - x]);
					sum -= 2 * v[n / 2].first;
					sum += 2 * v[n / 2-1].first;
					ans = max(ans, sum);
				}
			}
			else {
				ll sum = ra[n] - ra[n - x] - (ra[n - x]);
				ans = max(ans, sum);
			}
		}
		cout << ans << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}