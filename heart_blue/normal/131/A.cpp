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
const LL INF = 1e9 + 1;
const int N = 2e6;
int a[N];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int sum = 0;
	for (int i = 0; i < str.length(); i++) if (isupper(str[i])) sum++;
	if (sum == str.length() || (sum == str.length() - 1 && !isupper(str[0])))
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (isupper(str[i])) str[i] = tolower(str[i]);
			else str[i] = toupper(str[i]);
		}
	}
	cout << str << endl;
	return 0;
}