#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

int main() {
	int T; read(T);
	while (T--) {
		int n, d; read(n), read(d);
		int mx = 0, k = 0;
		for (int i = 1;i <= n; i++) {
			int x; read(x);
			mx = max(x, mx);
			if (x == d) k = 1;
		}
		if (k == 1) cout << 1 << endl;
		else if (d < mx) cout << 2 << endl;
		else if (d % mx == 0) cout << d / mx << endl;
		else cout << d / mx + 1 << endl;
	}
	return 0;
}