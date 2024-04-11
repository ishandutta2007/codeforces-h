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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (auto &x : v)
	{
		cin >> x;
		x *= 100;
		sum += x;
	}
	int tot = 450 * n;
	if (sum >= tot)
	{
		cout << 0 << endl;
		return 0;
	}
	int key = 0;
	sort(v.begin(), v.end());
	for (auto &x : v)
	{
		key++;
		sum += 500 - x;
		if (sum >= tot)
		{
			break;
		}
	}
	cout << key << endl;
	return 0;
}