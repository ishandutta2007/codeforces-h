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
const int N = 3e5 + 10;
int dp[N][10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	fill(dp[0], dp[0] + 10, 1);
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			dp[i][j] = dp[i - 1][j + 1];
		}
		dp[i][9] = (dp[i - 1][1] + dp[i - 1][0]) % INF;
	}
	while (ncase--)
	{
		LL ans = 0;
		int n, m;
		scanf("%d%d", &n, &m);
		while (n)
		{
			ans += dp[m][n % 10];
			n /= 10;
		}
		printf("%lld\n", ans % INF);
	}
	return 0;
}