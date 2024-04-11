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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

void solve() {
	int n, k; cin >> n >> k;
	char mp[3][105];
	rep(i, 3) {
		rep(j, 105) {
			mp[i][j] = '.';
		}
	}
	vector<bool> exi(3, false);
	vector<bool> nex(3, false);
	rep(i, 3) {
		rep(j, n) {
			cin >> mp[i][j];
			if (mp[i][j] == 's') {
				exi[i] = true;
			}
		}
	}
	int cur = 0;
	while (cur<n) {
		rep(i, 3)nex[i] = false;
		rep(i, 3) {
			if (!exi[i])continue;
			if (mp[i][cur + 1] != '.')continue;
			nex[i] = true;
			if (i - 1 >= 0 && mp[i - 1][cur + 1] == '.')nex[i - 1] = true;
			if (i + 1 < 3 && mp[i + 1][cur + 1] == '.')nex[i + 1] = true;
		}
		exi = nex;
		rep(i, 3) {
			nex[i] = false;
		}
		rep(i, 3) {
			if (!exi[i])continue;
			if (mp[i][cur + 1] == '.'&&mp[i][cur + 2] == '.') {
				nex[i] = true;
			}
		}
		exi = nex;
		cur += 3;
	}
	rep(i, 3) {
		if (exi[i]) {
			cout << "YES" << endl; return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	rep(aa, t) {
		solve();
	}
	//stop
	return 0;
}