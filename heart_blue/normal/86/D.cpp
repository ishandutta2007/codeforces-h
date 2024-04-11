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
LL res[N];
int a[N];
LL ans = 0;
const int block = 450;
void add(int x)
{
	cnt[x]++;
	ans += (2 * cnt[x] - 1)*x;
}
void sub(int x)
{
	cnt[x]--;
	ans -= (2 * cnt[x] + 1)*x;
}
class Node
{
public:
	int x, y;
	int pos;
	Node(int x = 0, int y = 0, int pos = 0)
	{
		this->x = x;
		this->y = y;
		this->pos = pos;
	}
	bool operator < (const Node& node) const
	{
		if (x / block != node.x / block) return x / block < node.x / block;
		if (y != node.y) return y < node.y;
		return pos < node.pos;
	}
};
vector<Node> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	v.resize(q);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < q; i++)
	{
		cin >> v[i].x >> v[i].y;
		v[i].pos = i;
	}
	sort(v.begin(), v.end());
	int l = 1, r = 0;
	for (auto &p : v)
	{
		int x = p.x;
		int y = p.y;
		while (l < x) sub(a[l++]);
		while (l > x) add(a[--l]);
		while (r < y) add(a[++r]);
		while (r > y) sub(a[r--]);
		res[p.pos] = ans;
	}
	for (int i = 0; i < q; i++)
	{
		printf("%lld\n", res[i]);
	}
	return 0;
}