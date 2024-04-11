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
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<
		chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

template<class T> struct mod_int {
	static constexpr int mod() { return T::mod; }

	int v;
	mod_int(long long _v = 0) 
		: v(norm(_v)) {}

	inline int norm(long long a) {
		return a < 0 ? a % mod() + mod() : a % mod();
	}
	mod_int neg() const { return v == 0 ? 0 : mod() - v; }

	template <typename U>
	explicit operator U() const { return v; }

	mod_int operator - () const { return neg(); }
	mod_int operator + () const { return mod_int(*this); }

	mod_int& operator -- () { if (v == 0) v = mod(); -- v; return *this; }
	friend mod_int operator -- (mod_int& a, int) { mod_int r = a; --a; return r; }
	mod_int& operator ++ () { ++ v; if (v == mod()) v = 0; return *this; }
	friend mod_int operator ++ (mod_int& a, int) { mod_int r = a; ++a; return r; }
	
#define defop(type, op) \
	friend inline type operator op (type a, const type &b) { return a op##= b; } \
	type& operator op##= (const type &oth)

	defop(mod_int, +) {
		if ((v += oth.v) >= mod()) v -= mod();
		return *this;
	}
	defop(mod_int, -) {
		if ((v -= oth.v) < 0) v += mod();
		return *this;
	}
	defop(mod_int, *) {
		return *this = norm(1ll * v * oth.v);
	}

	mod_int pow(long long b) const {
		mod_int a = *this, r = 1;
		while (b) {
			if (b&1) r *= a;
			b >>= 1; a *= a;
		}
		return r;
	}
	mod_int inv() const { return pow(mod() - 2); }

	defop(mod_int, /) { 
		return *this *= oth.inv();
	}
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

const int N = 2e5 + 5;

int n, m, bit[N], cur[N], cnt[N], b[N];
Mint fac[N], inv;

inline void add(int p, int v) {
	for (; p < N; p += p & -p)
		bit[p] += v;
}

inline int query(int p) {
	int r = 0;
	for (; p > 0; p -= p & -p)
		r += bit[p];
	return r;
}

inline int query(int l, int r) {
	return query(r) - query(l - 1);
}

void Hollwo_Pelw() {
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = fac[i - 1] * i;
	
	Mint res = 0, f = 1, inv = 1;

	cin >> n >> m;
	for (int i = 1, a; i <= n; i++) {
		cin >> a;
		add(a, 1);
		cnt[a] ++;
		inv *= cnt[a];
	}

	for (int i = 1; i <= m; i++)
		cin >> b[i];


	for (int i = 1; i <= min(n, m); i++) {
		res += query(1, b[i] - 1) * f * fac[n - i];
		if (query(b[i], b[i]) == 0)
			return cout << res / inv, (void) 0;
		++ cur[b[i]];
		f *= (cnt[b[i]] - cur[b[i]] + 1);
		add(b[i], -1);
	}

	if (n < m)
		res += f;

	cout << res / inv << '\n';
}