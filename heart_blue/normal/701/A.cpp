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
const int N = 1e2 + 10;
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], flag[i] = 0, sum += a[i];
	sum /= (n/2);
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		for (int j = i + 1; j <= n; j++)
		{
			if (flag[j]) continue;
			if (a[i] + a[j] == sum)
			{
				cout << i << ' ' << j << endl;
				flag[i] = 1;
				flag[j] = 1;
				break;
			}

		}
	}
	return 0;
}