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
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

template<class T> struct mod_int {
	static constexpr int mod() { return T::mod; }

	int v;
	mod_int(long long _v = 0) : v(norm(_v)) {}

	inline int norm(long long a) { return a < 0 ? a % mod() + mod() : a % mod(); }
	mod_int neg() const { return v == 0 ? 0 : mod() - v; }

	template <typename U> explicit operator U() const { return v; }
	mod_int operator - () const { return neg(); }
	mod_int operator + () const { return mod_int(*this); }
	mod_int& operator -- () { if (v == 0) v = mod(); -- v; return *this; }
	friend mod_int operator -- (mod_int& a, int) { mod_int r = a; --a; return r; }
	mod_int& operator ++ () { ++ v; if (v == mod()) v = 0; return *this; }
	friend mod_int operator ++ (mod_int& a, int) { mod_int r = a; ++a; return r; }
	
#define defop(type, op) \
	friend inline type operator op (type a, const type &b) { return a op##= b; } \
	type& operator op##= (const type &oth)

	defop(mod_int, +) { if ((v += oth.v) >= mod()) v -= mod(); return *this; }
	defop(mod_int, -) { if ((v -= oth.v) < 0) v += mod(); return *this; }
	defop(mod_int, *) { return *this = norm(1ll * v * oth.v); }
	defop(mod_int, /) { return *this *= oth.inv(); }

	inline mod_int pow(long long b) const {
		mod_int a = *this, r = 1;
		for (; b; b >>= 1, a *= a)
			if (b & 1) r *= a;
		return r;
	}
	inline mod_int inv() const { return pow(mod() - 2); }

#undef defop

#define compare(op) friend bool operator op \
(const mod_int& lhs, const mod_int& rhs) { return lhs.v op rhs.v; }
	compare(==) compare(!=) compare(<) compare(<=) compare(>) compare(>=)
#undef compare

	friend std::ostream& operator << (std::ostream& out, const mod_int& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& inp, mod_int& n) { long long x; inp >> x; n = mod_int(x); return inp; }
};

struct modular { static constexpr int mod = static_cast<int>(998244353); };

// struct modular { static int mod; };
// int modular::mod;

using Mint = mod_int<modular>;

const int MSK = 1 << 10;

Mint dp[2][MSK];
int n, m, S[MSK], T[MSK];

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int u, v; m --; )
		cin >> u >> v, S[v] |= 1 << u, T[u] |= 1 << v, T[v] |= 1 << u;
	
	dp[0][MSK - 1] = 1;
	for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < MSK; mask++) if (dp[i & 1][mask]) {
			
			for (int j = 0; j < 10; j++) if (mask >> j & 1)
				dp[(i & 1) ^ 1][(mask & (~S[j])) | ((MSK - 1) & (~T[j]))] += dp[i & 1][mask];

			dp[i & 1][mask] = 0;
		}
	}

	Mint res = 0;
	for (int i = 0; i < MSK; i++)
		res += dp[n & 1][i];
	cout << res << '\n';
}