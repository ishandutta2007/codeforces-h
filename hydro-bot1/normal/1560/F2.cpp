// Hydro submission #61220eb2e1b6d183ff865f64@1629621939037
// Version 2.6.2 by Eason_AC
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <ctime>
#include <set>
#include <queue>
#include <cctype>
#include <cassert>
#include <cinttypes>
#include <climits>
#define Tl template<typename T>
#define Tla template<typename T, typename... args>
#define F(T, i, a, b) for(T (i) = (a); (i) <= (b); ++(i))
#define R(T, i, a, b) for(T (i) = (a); (i) >= (b); --(i))
#define Fo(T, i, a, b, c) for(T (i) = (a); (i) <= (b); (i) += (c))
#define Re(T, i, a, b, c) for(T (i) = (a); (i) >= (b); (i) -= (c))
#define For(T, i, a, b, c) for(T (i) = (a); (i) <= (b); (i) *= (c))
#define Rep(T, i, a, b, c) for(T (i) = (a); (i) >= (b); (i) /= (c))
#define mes(a, x) memset((a), (x), sizeof((a)))
#define mec(a, b) memcpy((a), (b), sizeof((b)))
#define ll long long //No long long see your ancestor!!!
#define ull unsigned long long //Have long long see your ancestor!!!
#define lll __int128 //Have unsigned long long see your ancestor!!!
#define ld long double
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define yes puts("yes")
#define no puts("no")
#define no1 puts("-1")
#define iv inline void
#define ii inline int
#define ill inline ll
#define iull inline ull
#define i128 inline lll
#define ib inline bool
#define iT inline T
#define ilf inline double
#define ild inline ld
#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define mp make_pair
#define pub push_back
#define pob pop_back()
#define fi first
#define se second
#define pq priority_queue
#define iinf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
using namespace std;

namespace FullPre {
	Tl iv read(T &x) {T f = 1; x = 0; char c = getchar(); while(!isdigit(c)) {if(c == '-') f = -1; c = getchar();} while(isdigit(c)) {x = x * 10 + c - '0'; c = getchar();} x *= f;}
	Tla iv read(T& x, args &...Args) {read(x), read(Args...);}
	Tl iv write(T x) {if(x < 0) {putchar('-'); x = -x;} if(x > 9) write(x / 10); putchar(x % 10 + '0');}
	Tl iv print_char(T x, char ch) {write(x), putchar(ch);}
	Tl iv char_print(char ch, T x) {putchar(ch), write(x);}
	Tl iv print_space(T x) {print_char(x, ' ');}
	Tl iv print_space_mul(T x) {print_space(x);}
	Tla iv print_space_mul(T x, args ...Args) {print_space(x), print_space_mul(Args...);}
	Tl iv space_print(T x) {char_print(' ', x);}
	Tl iv space_print_mul(T x) {space_print(x);}
	Tla iv space_print_mul(T x, args ...Args) {space_print(x), space_print_mul(Args...);}
	Tl iv println(T x) {print_char(x, '\n');}
	Tl iv println_mul(T x) {println(x);}
	Tla iv println_mul(T x, args ...Args) {println(x), println_mul(Args...);}
	Tl iv lnprint(T x) {char_print('\n', x);}
	Tl iv lnprint_mul(T x) {lnprint(x);}
	Tla iv lnprint_mul(T x, args ...Args) {lnprint(x), lnprint_mul(Args...);}
	iv filein(string s) {freopen((s + ".in").c_str(), "r", stdin);}
	iv fileout(string s) {freopen((s + ".out").c_str(), "w", stdout);}
	iv file(string s) {filein(s), fileout(s);}
	Tl iT mymin(T a, T b) {return a < b ? a : b;}
	Tla iT mymin(T a, T b, args ...Args) {return mymin(mymin(a, b), Args...);}
	Tl iT mymax(T a, T b) {return a > b ? a : b;}
	Tla iT mymax(T a, T b, args ...Args) {return mymax(mymax(a, b), Args...);}
	Tl iT myabs(T a) {return a < 0 ? -a : a;}
	Tl iT mysq(T a) {return a * a;}
	Tl iT mygcd(T a, T b) {return !b ? a : mygcd(b, a % b);}
	Tla iT mygcd(T a, T b, args ...Args) {return mygcd(mygcd(a, b), Args...);}
	Tl iT mylcm(T a, T b) {return a / mygcd(a, b) * b;}
	Tla iT mylcm(T a, T b, args ...Args) {return mylcm(mylcm(a, b), Args...);}
	Tl iT myswap(T &a, T &b) {a ^= b ^= a ^= b;}
}
using namespace FullPre;
#define MT int Test; read(Test); while(Test--)
#define MCase int Test; read(Test); F(int, kase, 1, Test)

namespace Solution {
	const int N = 17;
	int n, k, cnt, fl, a[N], b[N], used[N];
	
	iv dfs(int x, int curk, int lim) {
		if(curk > k || fl) return;
		if(!x) {R(int, i, cnt, 1) write(b[i]); puts(""), fl = 1; return;}
		F(int, i, lim ? a[x] : 0, 9) {
			b[x] = i;
			if(!used[i]) used[i] = 1, dfs(x - 1, curk + 1, lim & (i == a[x])), used[i] = 0;
			else dfs(x - 1, curk, lim & (i == a[x]));
		}
	}
	
	iv Main() {
		MT {
			read(n, k);
			cnt = 0;
			while(!cnt || n) a[++cnt] = n % 10, n /= 10;
			fl = 0, mes(used, 0), dfs(cnt, 0, 1); 
		}
		return;
	}
}

int main() {
//	file("");
	Solution :: Main();
	return 0;
}
/*

*/