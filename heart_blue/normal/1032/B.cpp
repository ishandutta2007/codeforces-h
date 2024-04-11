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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	int cur = 0;
	for (int i = 1; i <= 5; i++)
	{
		if ((n - 1 + i) / i > 20) continue;
		int r = i, c = (n - 1 + i) / i;
		int o = r * c - n;
		cout << r << ' ' << c << endl;
		for (int a = 0; a < i; a++)
		{
			int tot = 0;
			for (int k = 0; k < o / i; k++) tot++, putchar('*');
			if (a < o % i) tot++, putchar('*');
			while (tot < c) putchar(str[cur++]), tot++;
			puts("");
		}
		break;
	}
	return 0;
}