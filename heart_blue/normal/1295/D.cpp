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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
LL getphi(LL n)
{
	LL ans = n;
	for (int i = 2; 1LL*i * i <= n; i++)
	{
		if (n % i) continue;
		ans -= ans / i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) ans -= ans / n;
	return ans;
}
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL a, m;
		scanf("%lld%lld", &a, &m);
		LL g = gcd(a, m);
		printf("%lld\n", getphi(m / g));
	}
	return 0;
}