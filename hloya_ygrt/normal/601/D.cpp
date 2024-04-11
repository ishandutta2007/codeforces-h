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
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 3e5 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 1;

int subtreesz[15 * maxn];
int tree[15 * maxn][26];
int triesz = 0;

void merge(int v1, int v2) {
	int s = 0;
	for (int i = 0; i < 26; i++) {
		if (tree[v2][i]) {
			if (tree[v1][i] == 0)
				tree[v1][i] = ++triesz;
			merge(tree[v1][i], tree[v2][i]);
		}
		s += subtreesz[tree[v1][i]];
	}
	subtreesz[v1] = s + 1;
}

string s;
int c[maxn];
int dif[maxn];

vector<int> g[maxn];
int bor[maxn];

void dfs(int v, int p = -1) {
	int mxBor = 0, szz = 0;

	for (int to:g[v]) {
		if (to == p)
			continue;
		dfs(to, v);
		int to_b = bor[to];
		if (subtreesz[to_b] > szz) {
			szz = subtreesz[to_b];
			mxBor = to_b;
		}
	}

	for (int to:g[v]) {
		if (to == p)
			continue;
		int to_b = bor[to];
		if (to_b != mxBor) {			
			merge(mxBor, to_b);
		}
	}

	bor[v] = ++triesz;
	if (mxBor == 0) {
		tree[bor[v]][s[v] - 'a'] = ++triesz;
		subtreesz[tree[bor[v]][s[v] - 'a']] = 1;
		subtreesz[bor[v]] = 2;
	} else {
		tree[bor[v]][s[v] - 'a'] = mxBor;
		subtreesz[bor[v]] = subtreesz[mxBor] + 1;
	}

	dif[v] = subtreesz[bor[v]] - 1;
}

int main() {
	//files1;
	int n;
	read(n);

	for (int i = 0; i < n; i++)
		read(c[i]);

	cin >> s;

	for (int i = 0; i < n - 1; i++) {
		int f, t;
		read(f, t);
		f--, t--;

		g[f].pb(t);
		g[t].pb(f);
	}

	dfs(0);

	int mx = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int cur = dif[i] + c[i];
		// cout << cur - c[i] << endl;
		if (cur > mx) {
			mx = cur;
			cnt = 0;
		}
		if (cur == mx) {
			cnt++;
		}
	}
	// exit(0);
	cout << mx << endl << cnt;
	return 0;
}