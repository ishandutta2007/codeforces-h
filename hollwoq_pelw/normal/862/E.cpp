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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

#define int long long
const int N = 1e5 + 5, inf = 1e18;

int n, m, q, tot, b[N], pre[N];
set<int> st;

int solve() {
	auto it = st.lower_bound(tot);
	return min(*it - tot, tot - *prev(it));
}

void Hollwo_Pelw() {
	cin >> n >> m >> q;
	for (int i = 1, a; i <= n; i++)
		cin >> a, tot += i & 1 ? a : -a;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= m; i++) {
		pre[i] = pre[i - 1] + (i & 1 ? b[i] : -b[i]);
	}
	st.insert(inf), st.insert(-inf);
	for (int i = n; i <= m; i++){
		int val = pre[i] - pre[i - n];
		if (i - n & 1) val *= -1;
		st.insert(val);
	}
	cout << solve() << "\n";
	for (int l, r, x; q --; ) {
		cin >> l >> r >> x;
		if ((r - l) % 2 == 0)
			tot += l & 1 ? x : -x;
		cout << solve() << "\n";
	}
}