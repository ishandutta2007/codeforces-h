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
		int sl, k; cin >> sl >> k;
		string s; cin >> s;
		bool flg = 0;
		for (int i = 0; i < sl; i++){
			if (s[i] != s[sl-1 - i]){ flg = 1; }
		}
		if (flg && k > 0){ cout << 2 << endl; }
		else{ cout << 1 << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}