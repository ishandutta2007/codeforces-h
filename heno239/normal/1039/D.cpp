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
const ld eps = 1e-8;
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

const int max_n = 1 << 19;
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

const int b = 500;
void solve() {
	int n; cin >> n;
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b); G[b].push_back(a);
	}
	vector<int> ids;
	queue<P> q; q.push({ 0,-1 });
	while (!q.empty()) {
		P p = q.front(); q.pop();
		int v = p.first, fr = p.second;
		ids.push_back(v);
		for (int to : G[v])if (to != fr) {
			q.push({ to,v });
		}
	}
	vector<int> val(n);
	vector<bool> chked(n + 1);
	vector<int> memo(n + 1);
	auto calc = [&](int k)->int {
		if (chked[k])return memo[k];
		chked[k] = true;
		int res = 0;
		fill(all(val), 0);
		per(i, ids.size()) {
			int id = ids[i];
			int ma = 0, ma2 = 0;
			bool exi = false;
			for (int to : G[id]) {
				if (ma < val[to]) {
					ma2 = ma;
					ma = val[to];
				}
				else if (ma2 < val[to]) {
					ma2 = val[to];
				}
				if (1 + ma + ma2 >= k) {
					exi = true; break;
				}
			}
			if (exi) {
				res++;
				val[id] = 0;
			}
			else val[id] = ma + 1;
		}
		return memo[k] = res;
	};

	vector<int> preval;
	vector<int> locs;
	for (int k = 1; k <= n; k += b) {
		preval.push_back(calc(k));
		locs.push_back(k);
	}

	int cur = 1;
	vector<int> ans(n + 1);
	while (cur <= n) {
		int val = calc(cur);
		//[le,ri)
		int le = upper_bound(all(locs), cur) - locs.begin(); le--;
		int ri = locs.size();
		while (ri - le > 1) {
			int m = (le + ri) / 2;
			if (preval[m] >= val) {
				le = m;
			}
			else ri = m;
		}
		le=max(cur, locs[le]);
		if (ri == locs.size())ri = n + 1;
		else ri = locs[ri];
		while (ri - le > 1) {
			int m = (le + ri) / 2;
			if (calc(m) == val)le = m;
			else ri = m;
		}
		for (int j = cur; j < ri; j++)ans[j] = val;
		cur = ri;
	}
	rep1(i, n)cout << ans[i] << "\n";
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