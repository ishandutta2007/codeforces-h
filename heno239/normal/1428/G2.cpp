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

typedef long long tr;
//
bool func(tr a, tr b) {
	return a <= b;
}
//namin[0,k),...,min[i,i+k),...,min[n-k,n)
vector<tr> slide_minimum(vector<tr> a, int k) {
	int n = a.size();
	vector<tr> res;
	vector<tr> deq(n);
	int s = 0, t = 0;
	rep(i, n) {
		while (s < t && func(a[deq[t - 1]], a[i]))t--;
		deq[t++] = i;
		if (i - k + 1 >= 0) {
			res.push_back(a[deq[s]]);
			if (deq[s] == i - k + 1)s++;
		}
	}
	return res;
}


ll dp[7][1000000];
void solve() {
	int k; cin >> k;
	vector<int> costs(9 * k + 1);
	rep(i, 9 * k + 1) {
		if (i % 3 == 0) {
			costs[i] = i / 3;
		}
		else {
			if (i < 9 * (k - 1))costs[i] = i / 3;
			else {
				costs[i] = 3 * (i / 9);
			}
		}
	}
	vector<ll> f(6); rep(i, 6)cin >> f[i];
	rep(i, 7)rep(j, 1000000)dp[i][j] = -INF;
	dp[0][0] = 0;
	rep(t, 6) {
		int s = 1;
		rep(j, t)s *= 10;
		rep(d, 3 * s) {
			deque<LP> vs;
			ll ad = 0;
			for (int x = d; x < 1000000; x += 3 * s) {
				LP nex = { dp[t][x],x };
				while (vs.size() && x-vs.front().second>(ll)9*(k-1)*s) {
					vs.pop_front();
				}
				while (vs.size() && vs.back().first + ad <= nex.first)vs.pop_back();
				vs.push_back({ nex.first - ad,nex.second });
				rep(y, 3)if (x + s * y < 1000000) {
					int to = x + s * y;
					dp[t + 1][to] = max(dp[t + 1][to], vs.front().first + ad);
				}
				ad += f[t];
			}
		}
		rep(i, 1000000) {
			for (int j = 9 * (k - 1); j <= 9 * k; j++) {
				ll p = i-(ll)j * s;
				if (p >= 0) {
					dp[t + 1][i] = max(dp[t + 1][i], dp[t][p] + costs[j] * f[t]);
				}
			}
		}
	}
	//cout << "? ";
	//cout << dp[1][23] << "\n";
	int q; cin >> q;
	rep(i, q) {
		int n; cin >> n;
		cout << dp[6][n] << "\n";
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