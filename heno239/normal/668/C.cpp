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
const int max_n = 1 << 16;
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

void solve() {
	int n; cin >> n;
	vector<ld> a(n), b(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	vector<ld> ra(n + 1), rb(n + 1);
	rep(i, n) {
		ra[i + 1] = ra[i] + a[i];
		rb[i + 1] = rb[i] + b[i];
	}
	vector<ld>rp(n + 1), rq(n + 1);
	rp[0] = 0; rp[n] = 1;
	rq[0] = 0; rq[n] = 1;
	rep1(i, n - 1) {
		ld vala = ra[i];
		ld valb = rb[n] - rb[i];
		ld t = vala;
		ld s = 1 + t - valb;
		//x^2-sx+t=0
		ld d = s * s - 4 * t;
		if (d < 0)d = 0;
		ld x1 = (s + sqrtl(d)) / (ld)2;
		ld x2 = (s - sqrtl(d)) / (ld)2;
		//cout << "? " << s << " " << t << "\n";
		//cout << "! " << x1 << " " << x2 << "\n";
		rp[i] = x2;
		rq[i] = x1;
	}
	vector<ld> p(n), q(n);
	rep(i, n) {
		p[i] = rp[i + 1] - rp[i];
		if (p[i] < 0)p[i] = 0;
		q[i] = rq[i + 1] - rq[i];
		if (q[i] < 0)q[i] = 0;
	}
	rep(i, n) {
		if (i > 0)cout << " "; cout << p[i];
	}cout << "\n";
	rep(i, n) {
		if (i > 0)cout << " "; cout << q[i];
	}cout << "\n";

	/*vector<ld> ma(n);
	vector<ld>mi(n);
	rep(i, n)rep(j, n) {
		ma[max(i, j)] += p[i] * q[j];
		mi[min(i, j)] += p[i] * q[j];
	}
	rep(i, n) {
		if (i > 0)cout << " "; cout << ma[i];
	}cout << "\n";
	rep(i, n) {
		if (i > 0)cout << " "; cout << mi[i];
	}cout << "\n";*/
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	//while(cin>>n,n)
	solve();
	return 0;
}