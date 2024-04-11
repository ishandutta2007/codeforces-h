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
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int o = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i * (i - 1) / 2 <= n) o = i;
	}
	printf("%d\n", o);
	int cur = 1;
	for (int i = 1; i <= o; i++)
	{
		for (int j = i + 1; j <= o; j++)
		{
			v[i].push_back(cur);
			v[j].push_back(cur);
			cur++;
		}
		for (auto& x : v[i])
			printf("%d ", x);
		puts("");
	}
	return 0;
}