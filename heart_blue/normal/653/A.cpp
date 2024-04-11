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

int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	map<int, int> m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		m[x] = 1;
	}
	string ans = "NO";
	for (auto &iter : m)
	{
		if (m.count(iter.first + 1) && m.count(iter.first - 1))
		{
			ans = "YES";
			break;
		}
	}
	cout << ans << endl;

	return 0;
}