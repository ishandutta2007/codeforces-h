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
#define MEM(a,b) memset((a),(vp),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] <= 2 * a[i - 1]) tot++;
		else tot = 1;
		ans = max(ans, tot);
	}
	cout << ans << endl;
	return 0;
}