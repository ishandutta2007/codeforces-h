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
const int N = 1e5 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	map<int, int> mc;
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		mc[x]++;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int tot = 0;
		for (auto &p : mc)
		{
			tot += p.second / i;
		}
		if (tot >= n) ans = i;
	}
	cout << ans << endl;
	return 0;
}