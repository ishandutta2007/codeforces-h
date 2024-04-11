// hloya template v25
  
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
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
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
  
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
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)5e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
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

ll c[maxn];
map<ll, int> allx;

set<int> v[maxn];
vector<pair<int, int> > b[maxn];

int p[maxn], sz[maxn];

int find(int v) {
	if (v == p[v])
		return v;
	return find(p[v]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (sz[u] > sz[v])
		swap(u, v);
	p[u] = v;
	sz[v] += sz[u];
}

void otk(int i) {
	for (int j : v[i]) {
		p[j] = j;
		sz[j] = 1;
	}
}

int main() {
	// files1;
	fast_io;

	srand(time(0));

	int n, m, k;
	read(n, m, k);

	for (int i = 0; i < n; i++) {
		read(c[i]);
	}

	vector<pair<int, int > > e;
	for (int i = 0; i < m; i++) {
		int a, b;
		read(a, b);
		a--, b--;

		e.pb(mp(a, b));	
		
		ll x = c[a] ^ c[b];
		// cout << x << endl;
		if (!allx.count(x))
			allx[x] = allx.size();
	}

	for (int i = 0; i < m; i++) {
		ll x = c[e[i].f] ^ c[e[i].s];
		int it = allx[x];
		v[it].insert(e[i].f);
		v[it].insert(e[i].s);
		b[it].push_back(e[i]);
	}

	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}

	ll ans = binpow<ll>(2, k);
	ans = 1ll * ans * binpow<ll>(2, n) % base;

	for (int i = 0; i < maxn; i++) {
		if (v[i].size()) {
			int cntcomp = v[i].size();
			for (int j = 0; j < b[i].size(); j++) {
				int u = b[i][j].f, v = b[i][j].s;
				if (find(u) != find(v)) {
					merge(u, v);
					cntcomp--;
				}
			}
			otk(i);

			ll cur = (binpow<ll>(2, (int)v[i].size()) - binpow<ll>(2, cntcomp) + base) % base;
			cur = 1ll * cur * binpow<ll>(2, n - (int)v[i].size()) % base;

			ans = (ans - cur + base) % base;
		}
	}

	cout << ans;
}