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
#include <cassert>
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
LL sum[N];
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = a[i] + sum[i - 1];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != 0)
			{
				if (sum[i] == 0) ans++;
				continue;
			}
			int j = i;
			map<LL, int> mc;
			mc[sum[j]]++;
			j++;
			int maxv = 1;
			while (j <= n && a[j] != 0)
			{
				maxv = max(maxv, ++mc[sum[j]]);
				j++;
			}
			i = j - 1;
			ans += maxv;
		}
		printf("%d\n", ans);
	}
	return 0;
}