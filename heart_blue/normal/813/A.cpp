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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		sum += x;
	}
	int m;
	cin >> m;
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		sum = max(sum, l);
		if (sum <= r && sum >= l)
		{
			cout << sum << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}