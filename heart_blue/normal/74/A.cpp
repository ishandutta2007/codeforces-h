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

const int INF = 1e9 + 7;
const int N = 2e5 + 1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    string ans;
    int maxv = -INF;
    int n;
    cin >> n;
    while (n--)
    {
        string str1;
        int a, b;
        int sum = 0;
        cin >> str1 >> a >> b;
        sum += a * 100 - b * 50;
        int m = 5;
        while (m--)
        {
            int x;
            cin >> x;
            sum += x;
        }
        if (sum > maxv) maxv = sum, ans = str1;
    }
    cout << ans << endl;
    return 0;
}