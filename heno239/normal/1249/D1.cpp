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

//ll inv(ll a, ll p) {
//	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
//}
//modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


vector<int> ad[1 << 18];
vector<int> de[1 << 18];

void solve() {
	int n, k; cin >> n >> k;
	vector<P> v(n);
	vector<bool> ban(n, false);
	rep(i, n) {
		int l, r; cin >> l >> r;
		v[i] = { l,r };
		ad[l].push_back(i);
		de[r].push_back(i);
	}
	set<P> st;
	vector<int> ans;
	rep(i, (1 << 18)) {
		for (int id : ad[i]) {
			st.insert({ v[id].second,id });
		}
		while (st.size() > k) {
			P p = *st.rbegin();
			ban[p.second] = true;
			ans.push_back(p.second);
			st.erase(p);
		}

		for (int id : de[i]) {
			if (ban[id])continue;
			st.erase({ v[id].second,id });
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i]+1;
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}