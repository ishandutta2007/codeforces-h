#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

string s[100020];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		if (s[i] == "0"){ cout << 0; return; }
	}
	int ptr = n;
	for (int i = 1; i <= n; i++){
		int cnt[10] = {};
		for (char ch : s[i]){ cnt[ch-'0'] += 1; }
		if (cnt[1] > 1){ ptr = i; }
		for (int j = 2; j < 10; j++){ if (cnt[j] > 0){ ptr = i; } }
	}
	int zer = 0;
	for (int i = 1; i <= n; i++){
		if (i == ptr){ continue; }
		zer += s[i].size()-1;
	}
	cout << s[ptr];
	while (zer--){ cout << 0; }
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}