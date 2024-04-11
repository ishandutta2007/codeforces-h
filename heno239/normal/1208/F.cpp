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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;

const int mn = 1 << 21;
vector<int> loc[mn];

P dp[mn];

void merge(P &a, P b) {
	P ret;
	if (a.first > b.first) {
		ret.first = a.first;
		if (a.second > b.first) {
			ret.second = a.second;
		}
		else{
			ret.second = b.first;
		}
	}
	else if(a.first<b.first){
		ret.first = b.first;
		if (a.first > b.second) {
			ret.second = a.first;
		}
		else {
			ret.second = b.second;
		}
	}
	else {
		ret.first = a.first;
		ret.second = max(a.second, b.second);
	}
	a = ret;
}
void merge(P &a, int x) {
	if (x > a.first) {
		a.second = a.first;
		a.first = x;
	}
	else if (x > a.second) {
		a.second = x;
	}
}
void solve(){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		loc[a[i]].push_back(i);
	}
	for (int i = mn - 1; i >= 0; i--) {
		dp[i] = { -mod,-mod };
		rep(j, 21) {
			if (i&(1 << j))continue;
			merge(dp[i], dp[i ^ (1 << j)]);
		}
		rep(j, loc[i].size()) {
			merge(dp[i], loc[i][j]);
		}
	}
	int ans = 0;
	rep(i, n - 2) {
		int sum = 0;
		per(j, 21) {
			int k = 1 << j;
			if (k&a[i])continue;
			int nex = sum + k;
			if (dp[nex].second > i) {
				sum = nex;
			}
		}
		ans = max(ans, sum + a[i]);
	}
	cout << ans << endl;

}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}