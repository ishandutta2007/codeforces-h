#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL sum[N];
int a[N];
map<LL, int> mc;
void solve(int l, int r)
{
	mc[sum[r] - sum[l - 1]] = 1;
	if (a[l] == a[r]) return;
	int mid = (a[l] + a[r]) / 2;
	int pos = upper_bound(a + l, a + r + 1, mid) - a;
	solve(l, pos - 1);
	solve(pos, r);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			sum[i] = a[i] + sum[i - 1];
		}
		mc.clear();
		solve(1, n);
		while (q--)
		{
			LL x;
			scanf("%lld", &x);
			if (mc.count(x)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}