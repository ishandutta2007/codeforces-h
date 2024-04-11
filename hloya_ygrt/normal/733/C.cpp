// hloya template v18

#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
// #define ld long double
#define pii pair<int,int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}

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

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

void reads(string & s) {
    string ans = "";
    char c = endl;
    while (c == endl || c == ' ')
        c = getchar();
    while (c != endl && c != ' ' && c)
        ans += c, c = getchar();
    s = ans;
}

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 5e2 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 5;

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

int a[maxn], b[maxn], sum[maxn];
pii lr[maxn];

string ans;
int res = 0;

int main() {
    int n;
    read(n);

    int kek = 0;
    for (int i = 0; i < n; i++) {
        read(a[i]);
        kek += a[i];
    }
    
    int k;
    read(k);
    for (int i = 0; i < k; i++) {
        read(b[i]);
        kek -= b[i];
    }

    if (kek)
        bad("NO");

    for (int l = 0, j = 0; l < n && j < k; j++) {
        int r = l - 1;
        while (r + 1 < n && sum[j] < b[j]) {
            r++;
            sum[j] += a[r];
        }
        lr[j] = mp(l, r);
        l = r + 1;
    }

    for (int i = 0; i < k; i++)
        if (sum[i] != b[i])
            bad("NO");

    for (int j = 0; j < k; j++) {
        vector<int> cur;
        int L = lr[j].f, R = lr[j].s;

        for (int i = L; i <= R; i++)
            cur.pb(a[i]);

        while (cur.size() > 1) {
            int mx = -1;
            for (int i = 0; i < cur.size(); i++) {
                mx = max(mx, cur[i]);
            }

            bool ok = 0;
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] == mx) {
                    if (i && cur[i - 1] < cur[i]) {
                        cur[i - 1] += cur[i];
                        res++;
                        ans += to_string(j + 1 + i);
                        ans += " L\n";
                        ok = 1;
                        cur.erase(cur.begin() + i);
                        break;
                    }
                    if (i != cur.size() - 1 && cur[i + 1] < cur[i]) {
                        cur[i + 1] += cur[i];
                        res++;
                        ans += to_string(j + 1 + i);
                        ans += " R\n";
                        ok = 1;
                        cur.erase(cur.begin() + i);
                        break;
                    }
                }
            }

            if (!ok) {
                bad("NO");
            }
        }
    }

    cout << "YES\n";
    cout << ans;
    return 0;
}