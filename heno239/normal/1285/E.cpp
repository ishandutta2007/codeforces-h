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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%mod;
		a = a * a%mod; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init() {
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

ll gc_d(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
ll lc_m(ll a, ll b) {
	ll g = gc_d(a, b);
	return a / g * b;
}

struct Node {
	Node* ch[2];

	Node() {
		ch[0] = ch[1] = NULL;
	}
};

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
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

void solve() {
	int n; cin >> n;
	vector<P> v;
	vector<int> x;
	rep(i, n) {
		int l, r; cin >> l >> r;
		v.push_back({ l,r });
		x.push_back(l);
		x.push_back(r);
	}
	x.push_back(-mod);
	x.push_back(mod);
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	if (x.size() == 1) {
		cout << 1 << endl; return;
	}
	map<int, int> mpx;
	rep(i, x.size())mpx[x[i]] = i;
	rep(i, n) {
		v[i].first = mpx[v[i].first];
		v[i].second = mpx[v[i].second];
	}
	sort(v.begin(), v.end());

	vector<int> cnt(x.size());
	rep(i, n) {
		cnt[v[i].first]++;
		cnt[v[i].second]--;
	}
	rep(i, (int)x.size() - 1) {
		cnt[i + 1] += cnt[i];
	}
	int ans = 1;
	BIT b(x.size());
	BIT c(x.size());
	rep(i, x.size() - 1) {
		if (cnt[i] == 1) {
			b.add(i, 1);
		}
	}
//	cout << exi00 << " " << exilaslas << endl;
	rep(i, x.size()-1) {
		if (cnt[i] == 0) {
			if (i > 0 && i < x.size() - 2)c.add(i, 1);
		}
	}
	vector<int> dcnt(x.size(), 0);
	rep(i, n)if (v[i].first == v[i].second)dcnt[v[i].first]++;
	rep(i, n) {
		int l = v[i].first, r = v[i].second;
		int val = c.sum(0,l)+c.sum(r,x.size())+b.sum(l, r) + 1;
		//cout << i << " ! " << val << endl;
		if (l == r) {
			if (dcnt[l] == 1)val--;
		}
		else {
			if (dcnt[l]==0&&cnt[l - 1] == 0 && cnt[l] == 1)val--;
			if (dcnt[r]==0&&cnt[r] == 0 && cnt[r - 1] == 1)val--;
			//if (l + 1 == r && cnt[l - 1] == 0 && cnt[l] == 1 && cnt[r] == 0)val++;
		}
		//cout << i<<" ! "<<val << endl;
		ans = max(ans, val);
	}
	//cout << "ans is ";
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(17);
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
		return 0;
}