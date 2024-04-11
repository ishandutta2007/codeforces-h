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
const int N = 1e2 + 10;
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
		string vs[N];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		string str;
		cin >> str;
		for (int i = 0; i < n; i++)
		{
			vs[a[i]] += str[i];
		}
		int flag = 1;
		for (int i = 0; i < N; i++)
		{
			if (vs[i].empty()) continue;
			if (count(vs[i].begin(), vs[i].end(), vs[i][0]) == vs[i].length()) continue;
			flag = 0;
			break;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}