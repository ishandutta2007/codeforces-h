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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
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
const int max_n = 1 << 21;
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


const int s = 10000003;
bool isp[s];
int meb[s];
int mi[s];
int eul[s];
vector<int> ps;
void init() {
	fill(isp + 2, isp + s, true);
	fill(mi + 2, mi + s, mod);
	fill(meb + 2, meb + s, 1);
	for (int i = 2; i < s; i++)eul[i] = i;
	for (int i = 2; i < s; i++) {
		if (!isp[i])continue;
		mi[i] = i;
		meb[i] *= -1;
		eul[i] = i - 1;
		ps.push_back(i);
		for (int j = 2 * i; j < s; j += i) {
			isp[j] = false;
			mi[j] = min(mi[j], i);
			meb[j] *= -1;
			eul[j] = (eul[j] / i) * (i - 1);
			if ((j / i) % i == 0)meb[j] = 0;
		}
	}
}
void solve() {
	int n; cin >> n;
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		int nump = eul[i];
		//distance 1
		ans += i - nump; 
		//minus d(i,i)
		ans--;
		//distance 3
		ans += 3 * nump;
		//minus d(1,i)
		ans -= 3;
		//cout << i << " " << ans << "\n";
	}

	vector<int> cnt(n + 1);
	for (int i = 2; i <= n; i++) {
		cnt[mi[i]]++;
	}
	//distance 0
	ll sum = 0;
	rep(i, ps.size()) {
		if (ps[i] > n)break;
		if (ps[i] * 2 > n) {
			ans -= 3 * sum;
		}
		sum += cnt[ps[i]];
	}
	//distance 2 without coprime
	ll num = 0;
	rep(i, ps.size()) {
		rep(j, ps.size()) {
			if ((ll)ps[i] * ps[j] > n)break;
			num += (ll)cnt[ps[i]] * cnt[ps[j]];
		}
	}
	//distance 2 with not coprime
	for (int g = 2; g <= n; g++) {
		if (meb[g] == 0)continue;
		ll cnum = 0;
		vector<int> vp;
		for (int j = g; j <= n; j += g) {
			vp.push_back(mi[j]);
		}
		sort(all(vp));
		int loc = vp.size() - 1;
		rep(i, vp.size()) {
			while (loc>=0&&(ll)vp[i] * vp[loc] > n)loc--;
			cnum += loc + 1;
		}
		num += cnum * meb[g];
	}
	//cout << num << "\n";
	ans -= num / 2;
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	init();
	//expr();

	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}