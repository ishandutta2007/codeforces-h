#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r")){
		freopen("hollwo_pelw.inp", "r", stdin);
		freopen("hollwo_pelw.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 2e5 + 5;

#define int long long

int n, a[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (count(a + 1, a + n + 1, 1) == 0)
		return cout << "YES\n", (void) 0;
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
		if (a[i] - a[i - 1] == 1)
			return cout << "NO\n", (void) 0;
	cout << "YES\n";
}