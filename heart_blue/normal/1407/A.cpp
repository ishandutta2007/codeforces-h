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
int a[N];
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
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			cnt += x;
		}
		if (n - (cnt - cnt % 2) <= n / 2)
		{
			cnt -= cnt & 1;
			printf("%d\n", cnt);
			while (cnt--) printf("1 ");
			puts("");
		}
		else
		{
			printf("%d\n", n / 2);
			for (int i = 0; i * 2 < n; i++) printf("0 ");
			puts("");
		}
	}
	return 0;
}