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
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );



void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		if (m == 1){
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++){ cout << i << endl; }
			continue;
		}
		if (n % 2 == 0){
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++){
				for (int j = 0; j < m; j++){
					cout << i + j*n << ' ';
				}
				cout << endl;
			}
		}
		else{
			cout << "NO" << endl;
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