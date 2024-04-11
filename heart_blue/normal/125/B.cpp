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
	string str;
	cin >> str;
	int cnt = 0;
	for(int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (!isalpha(c)) continue;
		if (str[i-1] != '/')
		{
			printf(string(cnt, ' ').c_str());
			printf("<%c>\n", c);
			cnt += 2;
		}
		else
		{
			cnt -= 2;
			printf(string(cnt, ' ').c_str());
			printf("</%c>\n", c);
		}
	}
	return 0;
}