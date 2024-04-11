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
		int l = 0, r = n - 1;
		vector<pair<int, int>> ans;
		while (l < r)
		{
			ans.emplace_back(l * 3 + 2, r * 3 + 3);
			l++, r--;
		}
		if (l == r)
		{
			ans.emplace_back(l * 3 + 1, l * 3 + 3);
		}
		printf("%d\n", ans.size());
		for (auto& [x, y] : ans)
			printf("%d %d\n", x, y);
	}
	return 0;
}