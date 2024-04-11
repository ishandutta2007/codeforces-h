#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, x[100000], y[100000], cnt[100000] = {};

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", x + i, y + i), --x[i], --y[i];
        ++cnt[x[i]];
    }
    REP(i, n)
        printf("%d %d\n", n - 1 + cnt[y[i]], n - 1 - cnt[y[i]]);
    return 0;
}