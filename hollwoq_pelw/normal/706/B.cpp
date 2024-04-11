#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS         std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n)      fixed << setprecision(n)

#define F           first
#define S           second
#define pii         pair<int, int>
#define pll         pair<ll, ll>
#define pdd         pair<ld, ld>

#define eb          emplace_back
#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()
#define len(a)      a.length()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

#define ms0(a)      memset(a, 0, sizeof(a));

const int mod1 = 998244353, mod2 = 1e9+7;
const int N = 100005, M = 200010;

void solve(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    
    int q; cin >> q;
    while(q--){
        int l = -1, r = n;
        int t; cin >> t;
        while(l < r-1){
            int m = (l+r)/2;
            if (a[m] > t) r = m;
            else l = m;
        }
        cout << l+1 << endl;
    }
}

int main(){
    IOS;
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}