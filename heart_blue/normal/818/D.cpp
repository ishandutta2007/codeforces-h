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
const int N = 1e6 + 10;
int cnt[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a;
	cin >> n >> a;
	MEM(cnt, 0);
	MEM(flag, 0);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (cnt[x] < cnt[a]) flag[x] |= 2;
		cnt[x]++;
		if (x != a)
		{
			if (cnt[x] >= cnt[a]) flag[x] |= 1;
			else flag[x] |= 2;
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (cnt[a] > cnt[i]) flag[i] |= 2;
		if (flag[i] == 1)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}