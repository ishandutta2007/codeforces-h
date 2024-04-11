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
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
// #include <unordered_map>
// #include <unordered_set>

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
T input(){
    T ans = 0, m = 1;
    char c = ' ';

    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }

    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
void read(T& a) {
    a = input<T>();
}

template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}

template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}

template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 3e5 + 5, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18 + 1;

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

int good;
int cnt[1000];

void add(char c) {
    if (cnt[c] == 0)
        good++;
    cnt[c]++;
}

void rem(char c) {
    if (cnt[c] == 1)
        good--;
    cnt[c]--;
}

int calc(int len, string& s) {
    for (int i = 0; i < len; i++)
        add(s[i]);
    int res = good;
    for (int i = 0; i + len < s.size(); i++) {
        rem(s[i]);
        add(s[i + len]);
        res = max(res, good);
    }
    for (int i = s.size() - len; i < s.size(); i++) {
        rem(s[i]);
    }
    return res;
}

int main() {
    int n;
    read(n);

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
        add(s[i]);
    int all = good;
    for (int i = 0; i < n; i++)
        rem(s[i]);

    int l = 1, r = s.size();
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (calc(m, s) == all)
            r = m;
        else
            l = m;
    }
    if (calc(l, s) == all)
        r = l;
    cout << r;
    return 0;
}