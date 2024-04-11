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
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxv = max(maxv, a[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == maxv) cnt++;
		else cnt = 0;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}