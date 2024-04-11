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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	while (cin >> str)
	{
		if (str.front() != '"')
		{
			printf("<%s>\n", str.c_str());
			continue;
		}
		char c;
		if (str.size() > 1 && str.back() == '\"')
		{
			str.front() = '<';
			str.back() = '>';
			puts(str.c_str());
			continue;
		}
		printf("<%s", str.substr(1).c_str());
		while (1)
		{
			c = getchar();
			if (c == '\"') break;
			putchar(c);
		}
		puts(">");
	}
	return 0;
}