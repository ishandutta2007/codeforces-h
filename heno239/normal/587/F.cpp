#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

//CFround326F
template<typename T>
struct fast_addsum {
private:
	int n, b, num;
	vector<T> blockval;
	vector<T> val;
	T init_c;
public:
	fast_addsum(int n_, T _init_c) {
		n_++;
		init_c = _init_c;
		n = n_;
		b = round(sqrt(n));
		num = (n + b - 1) / b;
		val.resize(n, init_c);
		blockval.resize(num, init_c);
	}
	void add(int i, T x) {
		//[i+1,n)
		int l = i + 1, r = n;
		int bl = l / b, br = r / b;
		int rl = l % b, rr = r % b;
		if (bl == br) {
			for (int j = l; j < r; j++)val[j] += x;
		}
		else {
			for (int j = rl; j < b; j++)val[bl * b + j] += x;
			for (int j = bl + 1; j < br; j++)blockval[j] += x;
			for (int j = 0; j < rr; j++)val[br * b + j] += x;
		}
	}
	T sum(int a) {
		return val[a] + blockval[a / b];
	}
	T sum(int a, int b) {
		return sum(b) - sum(a);
	}
};



struct qste {
	int id, l, r;
};
vector<ll> ans;
struct AhoCorasick {
	static const int SIZE = 27;
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
					//  	pma[pma[t].next[c]].accept.push_back(i);
				}
			}
		}
	}
	vector<int> rev;
	vector<vector<int>> ids;
	vector<vector<int>> G;
	void init(vector<string> s) {
		rev.resize(s.size());
		ids.resize(pma.size());
		G.resize(pma.size());
		rep(i, s.size()) {
			int loc = 0;
			rep(j, s[i].size()) {
				int c = s[i][j] - 'a';
				loc = pma[loc].next[c];
			}
			rev[i] = loc;
			ids[loc].push_back(i);
		}
		rep(i, pma.size()) {
			if (0 <= pma[i].next[26]) {
				G[pma[i].next[26]].push_back(i);
			}
		}
	}
	void querybig(string& s, vector<qste>& v) {
		int n = rev.size();
		int loc = 0;
		vector<int> val(pma.size());
		rep(j, s.size()) {
			int c = s[j] - 'a';
			loc = pma[loc].next[c];
			val[loc]++;
		}
		vector<int> num(n);
		function<int(int)> dfs = [&](int id)->int {
			int res = val[id];
			for (int to : G[id])res += dfs(to);
			for (int i : ids[id]) {
				num[i] += res;
			}
			return res;
		}; dfs(0);
		vector<ll> rnum(n + 1);
		rnum[0] = 0;
		rep(i, n) {
			rnum[i + 1] = rnum[i] + num[i];
		}
		for (qste q : v) {
			ans[q.id] += rnum[q.r] - rnum[q.l];
		}
	}
	vector<vector<qste>> vq;
	void querysmall(vector<string>& s, vector<int>& vid, vector<qste>& v) {
		int n = rev.size();
		vq.resize(pma.size());
		rep(i, vid.size()) {
			int id = vid[i];
			int loc = 0;
			rep(j, s[id].size()) {
				int c = s[id][j] - 'a';
				loc = pma[loc].next[c];
				vq[loc].push_back(v[i]);
			}
		}
		fast_addsum<int> st(n, 0);
		function<void(int)> dfs = [&](int id) {
			for (int i : ids[id]) {
				st.add(i, 1);
			}
			for (qste q : vq[id]) {
				ans[q.id] += st.sum(q.l, q.r);
			}
			for (int to : G[id])dfs(to);
			for (int i : ids[id]) {
				st.add(i, -1);
			}
		};
		dfs(0);
	}
};

void solve() {
	int n, q; cin >> n >> q;
	ans.resize(q);
	vector<string> s(n);
	rep(i, n)cin >> s[i];
	vector<int> l(q), r(q), k(q);
	rep(i, q) {
		cin >> l[i] >> r[i] >> k[i];
		l[i]--; k[i]--;
	}
	const int b = 300;
	AhoCorasick ac(s);
	ac.init(s);
	vector<vector<qste>> qs(n);
	rep(i, q) {
		qs[k[i]].push_back({ i,l[i],r[i] });
	}
	vector<int> oriid;
	vector<qste> oriq;
	rep(i, n) {
		if (s[i].size() > b) {
			ac.querybig(s[i], qs[i]);
		}
		else {
			rep(j, qs[i].size()) {
				oriid.push_back(i);
				oriq.push_back(qs[i][j]);
			}
		}
	}
	ac.querysmall(s, oriid, oriq);
	rep(i, q)cout << ans[i] << "\n";
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