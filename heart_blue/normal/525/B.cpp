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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	MEM(a, 0);
	int m;
	cin >> m;
	while (m--)
	{
		int x;
		cin >> x;
		a[x-1] ^= 1;
	}
	int n = str.length();
	int o = 0;
	for (int i = 0; i <= n - i - 1; i++)
	{
		if (a[i] ^ o)
		{
			swap(str[i], str[n - i - 1]);
		}
		o ^= a[i];
	}
	cout << str << endl;
	return 0;
}