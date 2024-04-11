#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
#define For(i, l, r)        for (int i = l; i < r; i++)
#define ForE(i, l, r)       for (int i = l; i <= r; i++)
#define Ford(i, r, l)       for (int i = r; i > l; i--)
#define FordE(i, r, l)      for (int i = r; i >= l; i--)
#define Fora(i, a)          for (auto i : a)
// I/O 
#define IOS                 std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << endl;
#define PrintVl(a)          Fora(ii, a) cout << ii << endl;
#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << endl;
#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << endl;
#define Ptest(x)            return cout << x, 0;
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calc    
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a, 0, sizeof(a));
#define ms1(a)              memset(a, 1, sizeof(a));
#define msn1(a)             memset(a, -1, sizeof(a));
// constant
const int mod1 = 998244353, mod2 = 1e9+7;
const int N = 100005, M = 200010;
//
void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    ll dp[n+1][3], cnt[3];
    // get cnt
    ll s = (r-l+1);
    cnt[0] = cnt[1] = cnt[2] = s/3;
    s %= 3;
    if (s>0) cnt[l%3]++;
    if (s>1) cnt[(l+1)%3]++;
    
    dp[0][0] = 1;
    dp[0][1] = dp[0][2] = 0;
    ForE(i,1,n){
        For(c,0,3){
            dp[i][c] = 0;
            For(k,0,3){
                dp[i][c] += dp[i-1][k]*cnt[(c+3-k)%3];
                dp[i][c] %= mod2;
            }
        }
    }
    cout << dp[n][0];
}

signed main(){
    IOS;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}