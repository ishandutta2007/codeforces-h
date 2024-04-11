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
const int N = 3e3 + 10;

int main()
{
    //freopen("input.txt","r",stdin);
    int x, y;
    cin >> x >> y;
    if (x == 0)
    {
        if (y > 0) cout << 4 * y - 2 << endl;
        else cout << 4 * -y << endl;
        return 0;
    }
    if (y == 0)
    {
        if (x == 1) cout << 0 << endl;
        if (x > 1) cout << 4 * x - 3 << endl;
        if (x < 1) cout << 4 * -x - 1 << endl;
    }
    if (x > 0 && y > 0)
    {
        if (y > x) cout << 4 * y - 2 << endl;
        else cout << 4 * x - 3 << endl;
    }
    if (x < 0 && y > 0)
    {
        if (y >= -x) cout << 4 * y - 2 << endl;
        else cout << 4 * -x - 1 << endl;
    }
    if (x < 0 && y < 0)
    {
        if (-y > -x) cout << 4 * -y << endl;
        else cout << 4 * -x - 1 << endl;
    }
    if (x > 0 && y < 0)
    {
        if (x == 1) cout << 4 * -y << endl;
        else
        {
            x--;
            if (-y >= x) cout << 4 * -y << endl;
            else cout << 4 * x + 1 << endl;
        }
    }
    return 0;
}