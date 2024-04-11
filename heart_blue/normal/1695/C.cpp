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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
bitset<N> b[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if ((n + m - 1) % 2 == 1)
		{
			puts("NO");
			for (int i = 0; i < n * m; i++)
				scanf("%*d");
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				b[i][j] = 0;
				if (i > 1) b[i][j] |= b[i - 1][j];
				if (j > 1) b[i][j] |= b[i][j - 1];
				if (i == 1 && j == 1) b[i][j][0] = 1;
				int x;
				scanf("%d", &x);
				if (x == 1) b[i][j] <<= 1;
			}
		}
		if (b[n][m][(n + m - 1) / 2]) puts("YES");
		else puts("NO");
	}
	return 0;
}