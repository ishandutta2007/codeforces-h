#pragma GCC target("avx2")
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

struct BIT {
private:
	vector<ll> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};


void solve() {
	int n, m; cin >> n >> m;
	vector<int> c(n);
	rep(i, n) {
		cin >> c[i]; c[i]--;
	}
	sort(all(c));
	int q; cin >> q;
	vector<int> l(q), r(q);
	rep(i, q) {
		cin >> l[i] >> r[i]; l[i]--; r[i]--;
	}
	vector<int> idl(q), idr(q);
	rep(i, q) {
		idl[i] = lower_bound(all(c), l[i]) - c.begin();
		idr[i] = upper_bound(all(c), r[i]) - c.begin();
	}
	//cout << idl[0] << " " << idr[0] << "\n";
	vector<char> ans(q, 'B');
	rep(i, 18) {
		int k = (1 << i);
		vector<vector<int>> ch(k);
		vector<vector<int>> qs(k);
		rep(j, q)qs[l[j] % k].push_back(j);
		BIT bt(n);
		vector<int> ste(n);
		rep(j, n) {
			int d = c[j] / k;
			int r = c[j] % k;
			if (r + 1 < k) {
				ch[r+1].push_back(j);
			}
			if (d % 2) {
				bt.add(j, 1);
				ste[j] = 1;
			}
		}
		rep(j, k) {
			for (int id : ch[j]) {
				if (ste[id])bt.add(id, -1);
				else bt.add(id, 1);
				ste[id] ^= 1;
			}
			for (int qid : qs[j]) {
				int s = bt.sum(idl[qid], idr[qid]);
				int d = l[qid] / k;
				if (d%2) {
					s = (idr[qid] - idl[qid]) - s;
				}
				//cout << "? " << i << " " << qid << " " << s << "\n";
				if (s%2)ans[qid] = 'A';
			}
		}
	}
	rep(i, q)cout << ans[i]; cout << "\n";
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