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
const ld eps = 1e-12;
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

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<P> v;
	rep(i, n - 1) {
		int le = i;
		while (i + 1 < n - 1 && s[i] == s[i + 1])i++;
		bool b = false; if (s[i] == '<')b = true;
		v.push_back({ b,i - le + 1 });
	}
	vector<int> ans1;
	vector<int> nums;
	rep(i, n - 1) {
		int le = i;
		while (i + 1 < n - 1 && s[i] == s[i + 1])i++;
		bool b = false; if (s[i] == '<')b = true;
		if (b) {
			nums.push_back(i-le+2);
		}
		else {
			rep(j, i - le)nums.push_back(1);
			if (le == 0)nums.push_back(1);
			if (i == n - 2)nums.push_back(1);
		}
	}
	int cur = n;
	for (int num : nums) {
		cur -= num;
		rep1(j, num) {
			ans1.push_back(cur + j);
		}
	}
	vector<int> ans2;
	nums.clear();
	rep(i, n - 1) {
		int le = i;
		while (i + 1 < n - 1 && s[i] == s[i + 1])i++;
		bool b = false; if (s[i] == '<')b = true;
		if (!b) {
			nums.push_back(i - le + 2);
		}
		else {
			rep(j, i - le)nums.push_back(1);
			if (le == 0)nums.push_back(1);
			if (i == n - 2)nums.push_back(1);
		}
	}
	cur = 1;
	for (int num : nums) {
		cur += num;
		rep1(j, num) {
			ans2.push_back(cur - j);
		}
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans1[i];
	}
	cout << endl;
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans2[i];
	}
	cout << endl;
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