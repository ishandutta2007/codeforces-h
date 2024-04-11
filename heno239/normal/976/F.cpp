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
constexpr ll mod = 1000000007 / 10000;
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

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
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
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
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
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

using mP = pair<modint, modint>;
//-----------------------------------

struct edge { int to; ll cap; int rev,id; };
struct Dinic {
private:
	int n;
	vector<vector<edge>> v;
	vector<int> dist, iter;
public:
	Dinic(int sz) :n(sz), v(sz), dist(sz), iter(sz) {}

	void addedge(int from, int to, ll cap,int id) {
		int x = v[to].size(), y = v[from].size();
		v[from].push_back({ to,cap,x,id });
		v[to].push_back({ from,0,y,id });
	}

	void bfs(int s) {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		dist[s] = 0;
		q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			rep(i, v[x].size()) {
				edge& e = v[x][i];
				if (e.cap > 0 && dist[e.to] < 0) {
					dist[e.to] = dist[x] + 1;
					q.push(e.to);
				}
			}
		}
	}

	ll dfs(int x, int t, ll f) {
		if (x == t)return f;
		for (int& i = iter[x]; i < (int)v[x].size(); ++i) {
			edge& e = v[x][i];
			if (e.cap > 0 && dist[x] < dist[e.to]) {
				ll d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					v[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	ll max_flow(int s, int t) {
		ll flow = 0;
		while (1) {
			bfs(s);
			if (dist[t] < 0)return flow;
			fill(iter.begin(), iter.end(), 0);
			ll f;
			while ((f = dfs(s, t, 1LL << 62)) > 0)flow += f;
		}
	}
	vector<int> query(int n,int m,int sup) {
		vector<int> res;
		vector<int> nrest(n,sup),mrest(m,sup);
		rep(i, n) {
			for (edge e : v[i]) {
				if (e.to < n + m && e.cap == 0) {
					res.push_back(e.id);
					nrest[i]--;
					mrest[e.to-n]--;
				}
			}
		}
		rep(i, n) {
			for (edge e : v[i]) {
				if (e.to < n + m && e.cap>0) {
					if (nrest[i] > 0) {
						nrest[i]--;
						res.push_back(e.id);
					}
				}
			}
		}
		rep(j, m) {
			for (edge e : v[j+n]) {
				if (e.to < n + m && e.cap == 0) {
					if (mrest[j] > 0) {
						mrest[j]--;
						res.push_back(e.id);
					}
				}
			}
		}
		return res;
	}
};


void solve() {
	int n, m, e; cin >> n >> m >> e;
	vector<P> vp;
	vector<int> d(n + m);
	rep(i, e) {
		int a, b; cin >> a >> b; a--; b--;
		vp.push_back({ a,b });
		d[a]++; d[b + n]++;
	}
	int mi = mod;
	rep(i, n + m)chmin(mi, d[i]);
	Dinic dc(n + m + 2);
	rep(j, e) {
		int a = vp[j].first;
		int b = vp[j].second;
		dc.addedge(a, b + n, 1, j + 1);
	}
	for (int i = 0; i <= mi; i++) {
		if (i > 0) {
			rep(j, n) {
				dc.addedge(n + m, j, 1, -1);
			}
			rep(j, m) {
				dc.addedge(j + n, n + m + 1, 1, -1);
			}
		}
		
		int f = dc.max_flow(n+m,n+m+1);
		vector<int> ans = dc.query(n, m,i);
		cout << ans.size() << " ";
		coutarray(ans);
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}