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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 10 + 10;

class Matrix
{
	int a[N][N];
	int sz;
public:
	int size()
	{
		return sz;
	}
	Matrix(int n = 0)
	{
		sz = n;
		MEM(a, 0);
	}
	int* operator [](int i)
	{
		return a[i];
	}
	Matrix ones(int n)
	{
		Matrix ret(n);
		for (int i = 0; i < n; i++) ret[i][i] = 1;
		return ret;
	}
	void init(int n = 2)
	{
		sz = n;
	}
	Matrix operator *(Matrix& m)
	{
		int n = m.size();
		Matrix ret(n);
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					ret[i][j] = (ret[i][j] + 1LL * a[i][k] * m[k][j]) % INF;
				}
			}
		}
		return ret;
	}
	Matrix operator +(Matrix& m)
	{
		int n = m.size();
		Matrix ret(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ret[i][j] = a[i][j] + m[i][j];
				if (ret[i][j] >= INF) ret[i][j] -= INF;
			}
		}
		return ret;
	}
	Matrix operator ^(LL b)
	{
		Matrix ret = ones(sz);
		Matrix A = *this;
		while (b)
		{
			if (b & 1) ret = ret * A;
			A = A * A;
			b >>= 1;
		}
		return ret;
	}
	Matrix powsum(int b)
	{
		Matrix ret(sz);
		Matrix A = ones(sz);
		for (int i = 30; i >= 0; i--)
		{
			ret = ret * A + ret;
			A = A * A;
			if (b >> i & 1)
			{
				A = A * (*this);
				ret = ret * (*this) + (*this);
			}
		}
		return ret;
	}
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL k;
	scanf("%d%lld", &n, &k);
	Matrix ans;
	ans = ans.ones(16);
	while (n--)
	{
		LL a, b;
		int c;
		scanf("%lld%lld%d", &a, &b, &c);
		b = min(b, k);
		Matrix A(16);
		for (int i = 0; i <= c; i++)
		{
			for (int j = 0; j <= c; j++)
			{
				if (abs(i - j) <= 1)
					A[i][j] = 1;
			}
		}
		A = A ^ (b - a);
		ans = A * ans;
	}
	printf("%d\n", ans[0][0]);
	return 0;
}