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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		LL ans = 0;
		int cnt0 = count(str.begin(), str.end(), '0');
		ans = 1LL * cnt0 * (n - cnt0);
		str += '*';
		int cnt = 1;
		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] == str[i - 1]) cnt++;
			else cnt = 1;
			ans = max(ans, 1LL * cnt * cnt);
		}
		printf("%lld\n", ans);

	}
	return 0;
}