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
typedef pair<ll, pl2> pl3;



void Main(){
	int t; cin >> t;
	while (t--){
		ll n, m; cin >> n >> m; n -= 1; m -= 1;
		if (n > m){ swap(n, m); }
		if (n == 0){
			if (m > 1){ cout << -1 << endl; }
			else{ cout << m << endl; }
		}
		else{
			if ( (n+m) & 1 ){ cout << m+m-1 << endl; }
			else{ cout << m+m << endl; }
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}