/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 2e5 + 5;

int64_t c, a[N << 1], res[N], val[N];
int dq[N], qh = 0, qt = -1;

void Hollwo_Pelw() {
	int n; cin >> n >> c;
	for (int i = 1; i < 2 * n; i++)
		cin >> a[i], a[i] += a[i - 1];
	// res[i] - res[j] >= min(c, a[2 * i - 1] - a[2 * j])
	// if a[2 * i - 1] - a[2 * j] >= c
	// 		res[i] - res[j] >= c 
	// else
	// 		res[i] - res[j] >= a[2 * i - 1] - a[2 * j]
	// 		res[i] - a[2 * i - 1] = max(res[j] - a[2 * j])

	dq[++ qt] = 0;

	for (int i = 1, j = 0; i <= n; i++) {
		while (j < i && a[2 * i - 1] - a[2 * j] >= c) j ++;
		while (qh <= qt && a[2 * i - 1] - a[2 * dq[qh]] >= c) qh ++;
		
		res[i] = max({
			(j ? res[j - 1] + c : 0),
			(qh <= qt ? val[dq[qh]] + a[2 * i - 1] : 0)
		});

		if (i < n) {
			val[i] = res[i] - a[2 * i];
			while (qh <= qt && val[dq[qt]] < val[i]) qt --;
			dq[++ qt] = i;
		}

		// cout << res[i] << " \n"[i == n];
	}
	cout << res[n] << '\n';
}