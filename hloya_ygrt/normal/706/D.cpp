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
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
#define ld long double
#define pii pair<int,int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

using namespace std;

template<typename T> 
void amax(T & x, T y) { x = max(x, y); }


template<typename T> 
void amin(T & x, T y) { x = min(x, y); }
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}
#include <unordered_map>
#include <unordered_set>

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

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 1e5 + 5, base = 1e9 + 7;
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

struct node {
    int cnt;
    node * nxt[2];
    node() {
       nxt[0] = nxt[1] = 0;
       cnt = 0;
    }
};

node * root;

void modify(int x, int y) {
    node * in = root;
    for (int i = 30; i >= 0; i--) {
        in -> cnt += y;
        int to = (x & (1 << i)) != 0;

        if (in -> nxt[to] == 0) in -> nxt[to] = new node();
        in = in -> nxt[to];    
    }

    in -> cnt += y;
}

int query(int x) {
    node * in = root;
    int res = 0;

    for (int i = 30; i >= 0; i--) {
        int to =(x & (1 << i)) == 0;

        if (in -> nxt[to] == 0 || in -> nxt[to] -> cnt == 0)
            to ^= 1;
        else
            res += (1 << i);

        in = in -> nxt[to];
    }

    return res;
}

int main() {
    int q;
    read(q);

    root = new node();
    modify(0, 1);
    
    while (q--) {
        char c = endl;
        while (c == endl)
            c = getchar();
        
        int x = input<int>();
        if (c == '+') {
            modify(x, 1);
        }
        if (c == '-') {
            modify(x, -1);
        }
        if (c == '?') {
            printf("%d\n", query(x));
        }
    }
    return 0;
}