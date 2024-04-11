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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	auto gen = mt19937(seed);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		if (n == 1) puts("1");
		else if (n == 2) puts("-1");
		else if (n == 3)
		{
			puts("2 9 7");
			puts("4 6 3");
			puts("1 8 5");
		}
		else
		{
			vector<int> v;
			for (int i = 1; i <= n; i++) v.push_back(i);
			while (1)
			{
				shuffle(v.begin(), v.end(), gen);
				int flag = 0;
				for (int i = 1; i < v.size(); i++)
				{
					if (abs(v[i] - v[i - 1]) == 1)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0) break;
			}
			for (int i = 1; i <= n; i++)
			{
				for (auto& x : v)
				{
					printf("%d ", x);
					x += n;
				}
				puts("");
			}
		}
	}
	return 0;
}