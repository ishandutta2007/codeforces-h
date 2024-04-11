#include <bits/stdc++.h>

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
 
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 5e3 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 1;

ll dp[maxn][maxn];
vector<pii> g[maxn];

bool used[maxn];
int n, m, t;

void dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].f, len = g[v][i].s;
		if (!used[to])
			dfs(to);

		for (int i = 2; i <= n; i++) {
			dp[v][i] = min(dp[v][i], dp[to][i - 1] + len);
		}
	}
}

int main() {
	//files1;
	read(n, m, t);

	for (int i = 0; i < m; i++) {
		int u, v, l;
		read(u, v, l);
		u--, v--;

		g[u].pb(mp(v, l));
	}

	for (int i = 0; i < n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = llinf;
	dp[n - 1][1] = 0;
	dfs(0);

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (dp[0][i] <= t)
			ans = i;
	}

	fast_io;
	cout << ans << endl;
	int v = 0, cur = ans;

	while (v != n - 1) {
		cout << v + 1 << ' ';
		for (int i = 0; i < g[v].size(); i++) {
			int to = g[v][i].f, len = g[v][i].s;
			if (dp[v][cur] == dp[to][cur - 1] + len) {
				v = to;
				break;
			}
		}
		cur--;
	}
	cout << n;
	return 0;
}