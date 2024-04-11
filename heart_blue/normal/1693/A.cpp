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
		LL sum = 0;
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			int x = a[i];
			if (sum == 0 && x > 0)
			{
				if (i != 1)
					flag = 0;
			}
			sum += x;
			if (sum < 0) flag = 0;
			if (sum > 0 && a[1] == 0) flag = 0;
		}
		if (sum == 0 && flag == 1) puts("YES");
		else puts("NO");
	}
	return 0;
}