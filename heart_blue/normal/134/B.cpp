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
const int N = 1e4 + 10;
const int maxv = 9999;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int getans(int n, int m)
{
	return m == 1 ? n - 1 : n / m + getans(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int ans = n;
	for (int i = 1; i <= n; i++)
	{
		if (gcd(i, n) != 1) continue;
		ans = min(ans, getans(n, i));
	}
	cout << ans << endl;
	return 0;
}