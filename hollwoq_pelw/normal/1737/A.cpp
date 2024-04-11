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
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

void Hollwo_Pelw(){
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> a(26);
	for (int i = 0; i < n; i++)
		a[s[i] - 'a'] ++;

	for (int i = 0; i < k; i++) {
		for (int j = 0, f = n / k; j < 26; j++) {
			if (a[j] && f) {
				a[j] --, f --;
			}
			else {
				cout << (char) (j + 'a');
				break;
			}
		}
	}
	cout << '\n';
}