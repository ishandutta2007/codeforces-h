#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );



void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int mn = 1e9, mnp = 1, mx = -1e9, mxp = 1;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			if (x < mn){ mn = x; mnp = i; }
			if (x > mx){ mx = x; mxp = i; }
		}
		cout << mnp << ' ' << mxp << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}