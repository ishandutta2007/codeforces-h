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
mP operator+(mP a, mP b) {
	return { a.first + b.first,a.second + b.second };
}
mP operator+=(mP& a, mP b) {
	a = a + b; return a;
}
mP operator-(mP a, mP b) {
	return { a.first - b.first,a.second - b.second };
}
mP operator-=(mP& a, mP b) {
	a = a - b; return a;
}

mt19937 mt(time(0));

const string drul = "DRUL";
string senw = "SENW";
//DRUL,or SENW
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//-----------------------------------------

bool isp(int x) {
	if (x == 1)return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return true;
}
mt19937 mtle(time(0));
uniform_int_distribution<> udle(900000000, 1100000000);
int findmodp() {
	int le = udle(mtle);
	while (!isp(le))le++;
	return le;
}

const ll t = 10;
const ll m = findmodp();
const ll m2 = findmodp();
const ll invt = mod_pow(t, m - 2, m);
const ll invt2 = mod_pow(t, m2 - 2, m2);
struct rolling_hash {
private:
	int sz;
	vector<LP> node;
	vector<LP> r;
	vector<LP> rt;
public:
	rolling_hash(const string& s) {
		int n = s.length();
		sz = n;
		node.resize(n + 1); r.resize(n + 1);
		node[0] = { 0,0 };
		rt.resize(n+1);
		rt[0] = { 1,1 };
		rep(i, n) {
			rt[i + 1].first = rt[i].first * t % m;
			rt[i + 1].second = rt[i].second * t % m2;
		}
		rep(i, n) {
			int z = s[i] - '0';
			node[i + 1].first = node[i].first + z * rt[n - 1 - i].first;
			node[i + 1].first %= m;
			node[i + 1].second = node[i].second + z * rt[n - 1 - i].second;
			node[i + 1].second %= m2;
		}

		ll a = 1,a2 = 1;
		rep(i, n) {
			r[i].first = a; a = invt * a % m;
			r[i].second = a2; a2 = invt2 * a2 % m2;
		}
	}
	LP calc(int le, int len) {
		LP ret = { node[le + len].first - node[le].first,node[le + len].second - node[le].second };
		if (ret.first < 0)ret.first += m;
		if (ret.second < 0)ret.second += m2;
		ret.first = ret.first * r[sz-(le+len)].first % m;
		ret.second = ret.second * r[sz-(le+len)].second % m2;
		return ret;
	}
};

void Z_algorithm(const string& s, vector<int>& a) {
	int sz = s.size();
	a.resize(sz);
	a[0] = sz;
	int i = 1, j = 0;
	while (i < sz) {
		while (i + j < sz && s[j] == s[i + j])++j;
		a[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < sz && k + a[k] < j)a[i + k] = a[k], ++k;
		i += k; j -= k;
	}
}

void solve() {
	string s; cin >> s;
	string x; cin >> x;
	rolling_hash rx(x);
	LP obj = rx.calc(0, x.size());
	rolling_hash rs(s);
	if (x.size() > 1) {
		rep(i, s.size()) {
			if (i + 2 * (x.size() - 1) <= s.size()) {
				LP v1 = rs.calc(i, x.size() - 1);
				LP v2 = rs.calc(i + x.size() - 1, x.size() - 1);
				v1.first += v2.first; v1.first %= m;
				v1.second += v2.second; v1.second %= m2;
				if (v1 == obj) {
					cout << i + 1 << " " << i + x.size() - 1 << "\n";
					cout << i + x.size() << " " << i + 2 * (x.size() - 1) << "\n";
					return;
				}
			}
		}
	}
	string sx = x + s;
	vector<int> zs;
	Z_algorithm(sx, zs);
	rep(i, s.size())if (i + x.size() <= s.size()) {
		int d = zs[x.size() + i];
		for (int dec = d; dec <= d + 1; dec++) {
			if (dec < x.size()) {
				int len = x.size() - dec;
				//cout << i << " " << len << "\n";
				//right
				if (i + x.size() + len <= s.size()) {
					LP v1 = rs.calc(i, x.size());
					LP v2 = rs.calc(i + x.size(), len);
					v1.first += v2.first; v1.first %= m;
					v1.second += v2.second; v1.second %= m2;
					
					if (v1 == obj) {
						cout << i + 1 << " " << i + x.size() << "\n";
						cout << i + x.size() + 1 << " " << i + x.size() + len << "\n";
						return;
					}
				}
				//left
				if (i >= len) {
					LP v1 = rs.calc(i, x.size());
					LP v2 = rs.calc(i - len, len);
					v1.first += v2.first; v1.first %= m;
					v1.second += v2.second; v1.second %= m2;
					if (v1 == obj) {
						cout << i -len+1 << " " << i << "\n";
						cout << i + 1 << " " << i + x.size() << "\n";
						return;
					}
				}
			}
		}
	}
	assert(false);
	//cout << "??\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init_f();
	//init();
	//expr();
	//while(true)
	//int t; cin >> t;rep(i,t)
	solve();
	return 0;
}