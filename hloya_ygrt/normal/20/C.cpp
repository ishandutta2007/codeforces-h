#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
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

using namespace std;

const int inf = 2e9;
const double eps = 1e-6;
const int maxn = 1e6 + 10, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

void bad(string mes = "Impossible"){cout << mes;exit(0);}

template<typename T>
string bin(T x){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % 2);
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
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
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + int(c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
T binpow(T n, T s)
{
    if (s == 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2) % base;
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

vector<pii> g[maxn];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++){
        int f, t, c;
        scanf("%d %d %d", &f, &t, &c);
        f--, t--;
        g[f].pb(mp(t, c));
        g[t].pb(mp(f, c));
    }

    set<pair<ll,int> > q;
    vector<ll> d(maxn, llinf);
    vector<int> p(maxn, -1);

    d[0] = 0;
    q.insert(mp(0, 0));

    while (!q.empty()){
        int v = (*q.begin()).second;
        q.erase(q.begin());

        for (int i = 0; i < g[v].size(); i++){
            int to = g[v][i].f;
            ll len = g[v][i].s;
            if (d[to] > d[v] + len){
                q.erase(mp(d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(mp(d[to], to));
            }
        }
    }

    if (d[n - 1] == llinf)
        bad("-1");
    vector<int> way;
    int in = n - 1;

    while (in != 0){
        way.pb(in);
        in = p[in];
    }
    way.pb(0);
    reverse(way.begin(), way.end());

    for (int i = 0; i < way.size(); i++)
        printf("%d ", way[i] + 1);
    return 0;
}