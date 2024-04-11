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
vector<vector<int>> ans;
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
		if (n % 4)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		LL sum = 0;
		for (int i = 1; i <= n / 2; i++) printf("%d ", i * 2), sum += i * 2;
		for (int i = 1; i < n / 2; i++) printf("%d ", i * 2 - 1), sum -= i * 2 - 1;
		printf("%lld\n", sum);
	}
	return 0;
}