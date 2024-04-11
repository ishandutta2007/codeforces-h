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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int l = 2, r = n;
    cout << 1;
    REP(i, k - 1) {
        if (i & 1) {
            cout << ' ' << l++;
        } else {
            cout << ' ' << r--;
        }
    }
    if (k & 1) for (int i = l; i <= r; ++i)
        cout << ' ' << i;
    else for (int i = r; i >= l; --i)
        cout << ' ' << i;
    cout << endl;
    return 0;
}