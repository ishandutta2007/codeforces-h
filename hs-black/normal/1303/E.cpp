
/*
 
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

const int N = 405;
char s[N], t[N];
int f[N], T, fl;

bool work(int m, int n, int p) {
	int s1 = p, s2 = n - p;
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1;i <= m; i++) {
		for (int j = min(s1, i - 1);j >= 0; j--) {
			if (s[i] == t[j+1]) Mx(f[j+1], f[j]);
			if (f[j] >= 0 && f[j] < s2 && s[i] == t[f[j]+1+s1]) f[j]++;
		}
	}
	for (int i = 0;i <= s1; i++)
		if (f[i] + i >= n) return 1;
	return 0;
}

int main() {
	for (read(T); T; T--) {
		scanf ("%s", s + 1);
		scanf ("%s", t + 1);
		int n = strlen(s + 1);
		int m = strlen(t + 1);
		fl = 0;
		for (int i = 1;i <= m; i++) if (work(n, m, i)) { fl = 1; break; }
		puts(fl ? "YES" : "NO");
	}
	return 0;
}

/*

2
feded
defed
ababcfeded
abcdebafed

*/