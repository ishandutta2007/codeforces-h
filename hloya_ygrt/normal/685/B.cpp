#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <unordered_set>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
 
#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define forn() for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define fill(x) memset((x), 0, sizeof((x)))
#define str(x) #x

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void runTime(int code = 3){exit(code);}
void timeLimit(){while(1);}

template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}

template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}

template<typename T>
void putOff(T collection, char separator = ' ', char terminator = '\n')
{
    int flag = 0;
    for (auto i:collection){
        if (flag++) cout << separator;
                    cout << i; 
    }
    cout << terminator;
}
 
template<typename T>
T dcm(string & s)
{
    T x = 0;
    for (int i = 0; i < s.size(); i++){
        x = (x * 2) + (s[i] == '1');
    }
    return x;
}
 
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (!((c >= '0' && c <= '9') || c == '-'))
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + int(c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
T parseNumber(string & s)
{
    T ans = 0, m = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-')
            m = -1;
        else {
            assert(s[i] >= '0' && s[i] <= '9');
            ans = (ans * (ll)10) + s[i] - '0';
        }
    }
    return ans * m;
}
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 3e5 + 1, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

int p[maxn];
vi g[maxn];

int st[maxn], mxOfSons[maxn];
pair<int,int> ctr[maxn];

bool Center(int tree, int v) {
    int N = st[tree];
    if (mxOfSons[v] <= N / 2 && st[tree] - st[v] <= N / 2)
        return 1;
    return 0;
}

void dfs(int v)
{
    st[v] = 1;
    if (g[v].empty()) {
        ctr[v].f = v;
        return;
    }

    vector<int> prob;

    for (int to:g[v]) {
        dfs(to);
        st[v] += st[to];
        mxOfSons[v] = max(mxOfSons[v], st[to]);
        if (ctr[to].f != -1)
            prob.pb(ctr[to].f);
        if (ctr[to].s != -1)
            prob.pb(ctr[to].s);   
    }

    for (int i = 0; i < prob.size(); i++) {
        int cur = prob[i];
        bool good = 0;
        if (Center(v, cur))
            good = 1;
        // if (v == 4){
        //     cout << good << endl;
        //     exit(0);
        // }
        while (!good) {
            cur = p[cur];
            if (Center(v, cur)){
                good = 1;
            }
            if (cur == v)
                break;
        }

        if (good) {
            if (ctr[v].f == -1)
                ctr[v].f = cur;
            else
                ctr[v].s = cur;
        }
    }
}

int main()
{
    int n, q;
    n = input<int>(), q = input<int>();

    for (int i = 1; i < n; i++){
        p[i] = input<int>() - 1;
        g[p[i]].pb(i);
    }

    for (int i = 0; i < n; i++)
        ctr[i] = mp(-1, -1);
    dfs(0);

    for (int i = 0; i < q; i++){
        int v = input<int>() - 1;
        if (ctr[v].f == -1)
            return 5;
        printf("%d\n", ctr[v].f + 1);
    }
    return 0;
}