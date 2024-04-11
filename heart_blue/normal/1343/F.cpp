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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
vector<int> v[N];
int flag[N][N];
int ans[N];
int vis[N];
int in[N];
bool solve(int key, int n)
{
	if (v[key].size() != 2) return false;
	swap(v[key].front(), v[key].back());
	MEM(vis, 0);
	MEM(in, 0);
	for (int i = 1; i < n; i++)
	{
		MEM(flag, 0);
	}
	for (int i = 1; i < n; i++)
	{
		if (i == key) continue;
		for (auto& x : v[i])
			flag[i][x] = 1;
	}
	ans[1] = v[key].front();
	ans[2] = v[key].back();
	vis[key] = 1;
	in[ans[1]] = 1;
	in[ans[2]] = 1;
	for (int i = 3; i <= n; i++)
	{
		int ok = 0;
		for (int j = 1; j < n; j++)
		{
			if (vis[j] || v[j].size() > i) continue;
			int cnt = 0;
			for (int k = 1; k < v[j].size(); k++)
			{
				cnt += flag[j][ans[i - k]];
				if (cnt != k) break;
			}
			if (cnt + 1 == v[j].size())
			{
				ok = 1;
				vis[j] = 1;
				for (auto& x : v[j])
				{
					if (!in[x])
					{
						in[x] = 1;
						ans[i] = x;
					}
				}
				break;
			}
		}
		if (ok == 0) return false;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	puts("");
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i < n; i++)
		{
			int sz;
			scanf("%d", &sz);
			v[i].clear();
			v[i].resize(sz);
			for (auto& x : v[i])
				scanf("%d", &x);
		}
		for (int i = 1; i < n; i++)
		{
			if (solve(i, n) || solve(i, n))
				break;
		}
	}
	return 0;
}