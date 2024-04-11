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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}

void solve() {
	int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
	a--; b--;
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int x, y; cin >> x >> y; x--; y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if (db <= 2 * da) {
		cout << "Alice\n"; return;
	}
	vector<int> dista(n, mod), distb(n, mod);
	queue<int> q;
	dista[a] = 0; q.push(a);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int to : G[v]) {
			if (dista[to] > dista[v] + 1) {
				dista[to] = dista[v] + 1;
				q.push(to);
			}
		}
	}
	distb[b] = 0; q.push(b);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int to : G[v]) {
			if (distb[to] > distb[v] + 1) {
				distb[to] = distb[v] + 1;
				q.push(to);
			}
		}
	}
	if (dista[b] <= da) {
		cout << "Alice\n"; return;
	}
	
	//calc max_dist
	vector<int> dist(n, mod);
	dist[0] = 0;
	q.push(0);
	int c1 = 0, c2 = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		c1 = v;
		for (int to : G[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
	}
	fill(all(dist), mod);
	dist[c1] = 0; q.push(c1);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		c2 = v;
		for (int to : G[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
	}
	int ma = 0;
	rep(i, n) {
		ma = max(ma, dist[i]);
	}
	
	if (ma > 2 * da) {
		cout << "Bob\n";
	}
	else {
		cout << "Alice\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
		solve();
	return 0;
}