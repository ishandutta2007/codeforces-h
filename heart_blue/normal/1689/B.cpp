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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int a[N];
int flag[N];
int b[N];
bool dfs(int n, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			printf("%d%c", b[i], " \n"[i + 1 == n]);
		return true;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == a[cur]) continue;
		if (flag[i]) continue;
		b[cur] = i;
		flag[i] = 1;
		if (dfs(n, cur + 1))
			return true;
		flag[i] = 0;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		MEM(flag, 0);
		if (!dfs(n, 0))
			puts("-1");
	}
	return 0;
}