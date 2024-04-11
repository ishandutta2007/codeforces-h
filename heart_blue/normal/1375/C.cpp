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
const int N = 3e5 + 10;
int a[N];
int pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		set<int> s;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			s.emplace(i);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			pos[a[i]] = i;
		}
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[*s.begin()] == i)
			{
				flag = 1;
				break;
			}
			if (a[*s.rbegin()] == i)
			{
				break;
			}
			s.erase(pos[i]);
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}