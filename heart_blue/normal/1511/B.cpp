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
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		c--;
		a -= c;
		b -= c;
		int x = 1;
		for (int i = 1; i < min(a, b); i++)
			x *= 10;
		int y = x;
		for (int i = min(a, b); i < max(a, b); i++)
			y *= 10;
		y++;
		if (a > b) swap(x, y);
		while (c--)
			x *= 10, y *= 10;
		printf("%d %d\n", x, y);
	}
	return 0;
}