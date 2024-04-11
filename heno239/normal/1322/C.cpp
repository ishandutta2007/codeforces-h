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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}


struct modint {
	ll n;
	constexpr modint() :n(0) { ; }
	constexpr modint(const ll m) : n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
constexpr bool operator==(const modint a, const modint b)noexcept { return a.n == b.n; }
constexpr modint operator+=(modint &a, const modint b)noexcept { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
constexpr modint operator-=(modint &a, const modint b)noexcept { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
constexpr modint operator*=(modint &a, const modint b)noexcept { a.n = ((ll)a.n*b.n) % mod; return a; }
constexpr modint operator+(modint a, const modint b)noexcept { return a += b; }
constexpr modint operator-(modint a, const modint b)noexcept { return a -= b; }
constexpr modint operator*(modint a, const modint b)noexcept { return a *= b; }
constexpr modint operator^(const modint a, const ll n)noexcept {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
constexpr modint operator/(const modint a, const modint b)noexcept { return a * (b ^ (mod - 2)); }

const int max_n = 1 << 18;
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
using mP = pair<modint, modint>;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

ll gcd(ll a, ll b) {
	if (a > b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
void solve() {
	int n, m; cin >> n >> m;
	vector<ll> c(n);
	rep(i, n)cin >> c[i];
	ll g = 0;
	vector<pair<vector<int>,ll>> ids(n);
	vector<ll> sum(n, 0);
	rep(i, m) {
		int l, r; cin >> l >> r; l--; r--;
		sum[l] += c[r];
		ids[r].first.push_back(l);
	}
	rep(i, n)g = gcd(g, sum[i]);
	rep(i, n) {
		ids[i].second = c[i];
		sort(all(ids[i].first));
	}
	sort(all(ids));
	rep(i, ids.size()) {
		if (ids[i].first.empty())continue;
		ll csum = ids[i].second;
		while (i + 1 < ids.size() && ids[i].first == ids[i + 1].first) {
			i++; csum += ids[i].second;
		}
		g = gcd(g, csum);
	}
	cout << g << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
		return 0;
}