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
const int N = 1e3 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> vs = { "aa","aba","aca","abca","acba","accabba","abbacca" };
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%*d");
		string str;
		cin >> str;
		int ans = -1;
		for (auto& s : vs)
		{
			if (str.find(s) != str.npos)
			{
				ans = s.length();
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}