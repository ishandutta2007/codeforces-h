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

const int max_n = 1 << 10;
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

#define ftt function<T(T,T)>
#define ftu function<T(T,U,int,int)>
#define fuu function<U(U,U)>

template<typename T, typename U>
struct SegT {
private:
	int n;
	vector<T> node;
	vector<U> lazy;
	T et; U eu;
	ftt f;
	ftu g;
	fuu h;
public:
	SegT(vector<T> ori, T _et, U _eu, ftt _f, ftu _g, fuu _h) {
		int sz = ori.size();
		et = _et, eu = _eu; f = _f, g = _g, h = _h;
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, et);
		lazy.resize(2 * n - 1, eu);
		rep(i, sz) {
			node[i + n - 1] = ori[i];
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int sz, T _et, U _eu, ftt _f, ftu _g, fuu _h) {
		et = _et, eu = _eu; f = _f, g = _g, h = _h;
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, et);
		lazy.resize(2 * n - 1, eu);
	}
	void eval(int k, int l, int r) {
		node[k] = g(node[k], lazy[k], l, r);
		if (r - l > 1) {
			lazy[2 * k + 1] = h(lazy[k], lazy[2 * k + 1]);
			lazy[2 * k + 2] = h(lazy[k], lazy[2 * k + 2]);
		}
		lazy[k] = eu;
	}
	void add(U x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = h(x, lazy[k]);
			eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return et;
		if (a <= l && r <= b)return node[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int loc, T x) {
		int k = 0, l = 0, r = n;
		stack<P> st;
		while (k < n - 1) {
			eval(k, l, r);
			st.push({ l,r });
			if (loc < (l + r) / 2) {
				k = 2 * k + 1;
				r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2;
				l = (l + r) / 2;
			}
		}
		eval(k, l, r);
		st.push({ l,r });
		node[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			st.pop();
			l = st.top().first, r = st.top().second;
			eval(2 * k + 1, l, (l + r) / 2);
			eval(2 * k + 2, (l + r) / 2, r);
			node[k] = f(node[2 * k + 1], node[2 * k + 2]);
		}
	}
};

void solve() {
	int n; cin >> n; string s; cin >> s;
	vector<P> ori(n, { 0,1 });
	auto f = [&](P a, P b)->P {
		if (a.first == b.first) {
			return { a.first,a.second + b.second };
		}
		else {
			return min(a, b);
		}
	};
	auto g = [&](P a, int b, int l, int r)->P {
		return { a.first + b,a.second };
	};
	auto h = [&](int a, int b)->int {return a + b; };
	SegT<P, int> st(ori, { mod,0 }, 0, f, g, h);
	int ri = n;
	ll sum = 0;
	ll ans = 0;
	per(i, s.size()) {
		if (s[i] == '0') {
			ans += sum; ri = i;
		}
		else {
			int cnt = ri - i;
			P p = st.query(ri, n);
			if (p.first < cnt) {
				st.add(1, ri, ri + p.second);
				sum += p.second;
			}
			st.add(1, i, ri);
			sum += ri - i;
			ans += sum;
		}
	}
	cout << ans << "\n";
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