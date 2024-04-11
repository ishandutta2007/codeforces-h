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
const int N = 2e2 + 10;
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
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '0') cnt0++;
			else break;
		}
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] == '1') cnt1++;
			else break;
		}
		cout << string(cnt0, '0');
		if (cnt0 + cnt1 < n) cout << '0';
		cout << string(cnt1, '1') << '\n';
	}
	return 0;
}