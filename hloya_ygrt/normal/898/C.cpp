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
  
#include <bits/stdc++.h>
#include <valarray>
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

bool suff(const string& s, const string& t) {
    if (t.size() > s.size())
        return 0;
    for (int i = s.size() - 1, j = t.size() - 1; j >= 0; i--, j--) {
        if (s[i] != t[j])
            return 0;
    }
    return 1;
}

vector<string> a[25];
string name_[25];

map<string, int> sot;

int main() {
    // cout << suff("aba", "bbbbb");
    // return 0;
    // files1;
    int n;
    fast_io;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (!sot.count(name)) {
            sot[name] = cnt++;
            name_[sot[name]] = name;
        }

        int pos = sot[name];

        int m;
        cin >> m;
        
        // vector<string> a(m);
        for (int i = 0; i < m; i++) {
            string t;
            cin >> t;
            a[pos].pb(t);
        }
    }

    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        vector<string> a = ::a[i];

        sort(all(a));

        vector<string> tmp;
        for (int i = 0; i < a.size(); i++)
            if (i == 0 || a[i - 1] != a[i])
                tmp.pb(a[i]);
        a = tmp;

        vector<string> b;
        for (int i = 0; i < a.size(); i++) {
            bool suf = 0;
            for (int j = 0; j < a.size(); j++)
                if (i != j && suff(a[j], a[i]))
                    suf = 1;
            if (!suf)
                b.pb(a[i]);
        }

        cout << name_[i] << ' ' << b.size() << ' ';
        for (int j = 0; j < b.size(); j++)
            cout << b[j] << ln(j, b.size());
    }
    return 0;
}