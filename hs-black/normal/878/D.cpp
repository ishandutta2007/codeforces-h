/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)


*/

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

#include <bitset>
const int N = 100059;
int a[13][N], id[N], n, k, q, cnt;
bitset<5009> bit[N];
int main() { 
	read(n), read(k), read(q), cnt = k;
	int all = 1 << k;
	for (int i = 1;i <= k; ++i) {
		for (int j = 1;j <= n; ++j) read(a[i][j]);
		for (int s = 0;s < all; ++s)
			if (s >> (i - 1) & 1) bit[i][s] = 1;
	}
	for (int i = 1, op, x, y;i <= q; ++i) {
		read(op), read(x), read(y);
		if (op == 1) bit[++cnt] = bit[x] | bit[y];
		if (op == 2) bit[++cnt] = bit[x] & bit[y];
		if (op == 3) {
			for (int j = 1;j <= k; ++j) id[j] = j;
			sort(id + 1, id + k + 1, [&](int tt, int pp) { return a[tt][y] < a[pp][y]; });
			int s = 0, ans;
			for (int j = k;j >= 1; --j) {
				s |= 1 << id[j] - 1;
				if (bit[x][s]) { ans = a[id[j]][y]; break; }
			}
			write(ans);
		}
	}
	return 0;
}