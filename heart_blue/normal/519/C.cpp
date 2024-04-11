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
const int N = 1E7;


int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);

	int a, b;
	cin >> a >> b;
	int cnt = 0;
	while (a&&b&&a + b > 2)
	{
		if (a < b) swap(a, b);
		cnt++;
		a -= 2;
		b--;
	}
	cout << cnt << endl;
	return 0;
}