#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;

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
const ld eps = 1e-4;
const ld pi = acosl(-1.0);

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
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
const int max_n = 1 << 20;
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int get_premitive_root() {
	int primitive_root = 0;
	if (!primitive_root) {
		primitive_root = [&]() {
			set<int> fac;
			int v = mod - 1;
			for (ll i = 2; i * i <= v; i++) while (v % i == 0) fac.insert(i), v /= i;
			if (v > 1) fac.insert(v);
			for (int g = 1; g < mod; g++) {
				bool ok = true;
				for (auto i : fac) if (mod_pow(g, (mod - 1) / i) == 1) { ok = false; break; }
				if (ok) return g;
			}
			return -1;
		}();
	}
	return primitive_root;
}
const int proot = get_premitive_root();

typedef vector <modint> poly;
void dft(poly& f, bool inverse = false) {
	int n = f.size(); if (n == 1)return;

	static poly w{ 1 }, iw{ 1 };
	for (int m = w.size(); m < n / 2; m *= 2) {
		modint dw = mod_pow(proot, (mod - 1) / (4 * m)), dwinv = (modint)1 / dw;
		w.resize(m * 2); iw.resize(m * 2);
		for (int i = 0; i < m; i++)w[m + i] = w[i] * dw, iw[m + i] = iw[i] * dwinv;
	}
	if (!inverse) {
		for (int m = n; m >>= 1;) {
			for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
				for (int i = s; i < s + m; i++) {
					modint x = f[i], y = f[i + m] * w[k];
					f[i] = x + y, f[i + m] = x - y;
				}
			}
		}
	}
	else {
		for (int m = 1; m < n; m *= 2) {
			for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
				for (int i = s; i < s + m; i++) {
					modint x = f[i], y = f[i + m];
					f[i] = x + y, f[i + m] = (x - y) * iw[k];
				}
			}
		}
		modint n_inv = (modint)1 / (modint)n;
		for (modint& v : f)v *= n_inv;
	}
}
poly multiply(poly g, poly h) {
	int n = 1;
	int pi = 0, qi = 0;
	rep(i, g.size())if (g[i])pi = i;
	rep(i, h.size())if (h[i])qi = i;
	int sz = pi + qi + 2;
	while (n < sz)n *= 2;
	g.resize(n); h.resize(n);
	dft(g); dft(h);
	rep(i, n) {
		g[i] *= h[i];
	}
	dft(g, true);
	return g;
}
void normalize(poly& p) {
	while (p.size() > 1 && p.back() == (modint)0)p.pop_back();
	rep(i, p.size())if (p[i] != (modint)0)p[i] = 1;
}
void solve(){
	int n, k; cin >> n >> k;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	poly p;
	rep(i, n) {
		if (a[i] >= p.size()) {
			p.resize(a[i] + 1);
		}
		p[a[i]] = 1;
	}
	poly x = { 1 };
	while (k > 0) {
		if (k & 1) {
			x = multiply(x, p);
			normalize(x);
		}
		k >>= 1;
		if (k == 0)break;
		p = multiply(p, p);
		normalize(p);
	}
	vector<int> anss;
	rep(i, x.size()) {
		if (x[i] != (modint)0)anss.push_back(i);
	}
	rep(i, anss.size()) {
		if (i > 0)cout << " "; cout << anss[i];
	}cout << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}