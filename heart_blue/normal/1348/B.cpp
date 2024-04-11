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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto& x : v) cin >> x;
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		if (v.size() > k)
		{
			puts("-1");
			continue;
		}
		printf("%d\n", n * k);
		while (v.size() < k)
			v.push_back(v[0]);
		while (n--)
		{
			for (auto& x : v)
				printf("%d ", x);
		}
		puts("");
	}

	return 0;
}