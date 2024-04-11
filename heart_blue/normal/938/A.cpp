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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s = "aeiouy";
	map<char, int> mc;
	for (auto &c : s) mc[c] = 1;
	string str;
	int n;
	cin >> n;
	cin >> str;
	string ans;
	for (auto &c : str)
	{
		if (!ans.empty() && mc[c] && mc[ans.back()]) continue;
		ans.push_back(c);
	}
	cout << ans << endl;
	return 0;
}