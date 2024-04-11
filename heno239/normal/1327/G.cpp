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
constexpr ll mod = 998244353;
//constexpr ll mod = 1000000007;
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
void pout(P& p) {
	cout << p.first << " " << p.second << "\n";
}
void pout(LP& p) {
	cout << p.first << " " << p.second << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	//if (x == 0)return 0;
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
bool operator<(modint a, modint b) { return a.n < b.n; }
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
void pout(LDP& p) {
	cout << p.first << " " << p.second << "\n";
}
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
/*const int mn = 100005;
bool isp[mn];
vector<int> ps;
void init() {
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
		}
	}
}*/

//[,val)
template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}

//[val,)
template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;

const string drul = "DRUL";
//DRUL
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------
struct AhoCorasick {
	static const int SIZE = 15;
	struct State {
		int index, next[SIZE];
		//vector<int> accept;
		State(int index) : index(index) {
			for (int i = 0; i < SIZE; i++)next[i] = -1;
		}
	};
	vector<State> pma;
	//vector<int> lens;

	AhoCorasick(const vector<string>& str, char base_c = 'a') {
		pma.clear();
		pma.push_back(State(0));
		//lens.clear();
		rep(i, str.size()) {
			int t = 0;
			for (char c : str[i]) {
				if (pma[t].next[c - base_c] == -1) {
					int m = pma.size();
					pma[t].next[c - base_c] = m;
					pma.push_back(State(m));
				}
				t = pma[t].next[c - base_c];
			}
			//pma[t].accept.push_back(lens.size());
			//lens.push_back(str[i].size());
		}
		queue<int> que;
		for (int c = 0; c < SIZE - 1; c++) {
			if (pma[0].next[c] != -1) {
				pma[pma[0].next[c]].next[SIZE - 1] = 0;
				que.push(pma[0].next[c]);
			}
			else {
				pma[0].next[c] = 0;
			}
		}
		while (!que.empty()) {
			int t = que.front();
			que.pop();
			for (int c = 0; c < SIZE - 1; c++) {
				if (pma[t].next[c] != -1) {
					que.push(pma[t].next[c]);
					int r = pma[t].next[SIZE - 1];
					while (pma[r].next[c] == -1) r = pma[r].next[SIZE - 1];
					pma[pma[t].next[c]].next[SIZE - 1] = pma[r].next[c];
					//for (int i : pma[pma[r].next[c]].accept)
					//	pma[pma[t].next[c]].accept.push_back(i);
				}
			}
		}
	}
	int sub(int index, int c) {
		return pma[index].next[c] != -1 ?
			pma[index].next[c] :
			pma[index].next[c] = sub(pma[index].next[SIZE - 1], c);
	}
	vector<int> cost;
	void complete(vector<string> s,vector<int> c) {
		cost.resize(pma.size());
		vector<vector<int>> G(pma.size());
		for (int i = 1; i < pma.size(); i++) {
			G[pma[i].next[SIZE - 1]].push_back(i);
		}
		rep(i, s.size()) {
			int loc = 0;
			for (char c : s[i]) {
				loc = sub(loc, c - 'a');
			}
			cost[loc] += c[i];
		}
		function<void(int)> initdfs = [&](int id) {
			for (int to : G[id]) {
				cost[to] += cost[id];
				initdfs(to);
			}
		}; initdfs(0);
		//coutarray(cost);
	}
	ll query(string s) {
		vector<int> qs;
		rep(i, s.size())if (s[i] == '?')qs.push_back(i);
		const int m = 14;
		int n = pma.size();
		vector<vector<ll>> dp(n, vector<ll>(1 << m, -INF));
		auto cop = dp;
		dp[0][0] = 0;
		auto upd = [&](string t) {
			vector<int> nex(n);
			vector<ll> ad(n);
			rep(i, n)nex[i] = i;
			for (char c : t) {
				rep(i, n) {
					nex[i] = sub(nex[i], c - 'a');
					ad[i] += cost[nex[i]];
				}
			}
			swap(dp, cop);
			rep(i, n)rep(j, (1<<m)) {
				chmax(dp[nex[i]][j], cop[i][j] + ad[i]);
				cop[i][j] = -INF;
			}
		};
		auto upd1 = [&]() {
			rep(i, n)rep(j, (1 << m)) {
				if (dp[i][j] <= -INF / 2)continue;
				rep(k, m) {
					if (j & (1 << k))continue;
					int ni = sub(i, k);
					int nj = j ^ (1 << k);
					chmax(cop[ni][nj], dp[i][j] + cost[ni]);
				}
			}
			rep(i, n)rep(j, (1 << m)) {
				dp[i][j] = cop[i][j];
				cop[i][j] = -INF;
			}
		};
		int cl = 0;
		for (int id : qs) {
			string u = s.substr(cl, id - cl); cl = id + 1;
			upd(u);
			upd1();
		}
		string u = s.substr(cl, s.size() - cl);
		upd(u);

		ll res = -INF;
		rep(i, n)rep(j, (1 << m)) {
			chmax(res, dp[i][j]);
		}
		return res;
	}
	/*vector<int> query(string& t) {
		int index = 0;
		vector<int> ret(lens.size(), -1);
		rep(i, t.size()) {
			int c = t[i];
			index = sub(index, c);
			for (int j : pma[index].accept) {
				if (ret[j] != -1) continue;
				ret[j] = i - lens[j] + 1;
			}
		}
		return ret;
	}*/
};




void solve(){
	int m; cin >> m;
	vector<string> s(m);
	vector<int> c(m);
	rep(i, m)cin >> s[i] >> c[i];
	AhoCorasick aho(s);
	string t; cin >> t;
	aho.complete(s, c);
	ll ans = aho.query(t);
	cout << ans << "\n";
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