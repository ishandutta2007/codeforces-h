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
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(b, 0);
	int o = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > n) continue;
		b[a[i]] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] > n || b[a[i]] > 0)
		{
			while (b[o] != 0) o++;
			b[o] = 1;
			a[i] = o;
		}
		else
		{
			b[a[i]] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}