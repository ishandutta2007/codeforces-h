#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ll INF = 1ll * mod * mod;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    ll pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    vector<int> pr(maxn);
    pr[2] = 1;
    for(int i=3; i<maxn; i+=2)
        pr[i] = 1;

    for(int i=3; i*i<maxn; i+=2)
        if( pr[i] )
            for(int j=i*i; j<maxn; j+=2*i)
                pr[j] = 0;

    int tc;
    cin >> tc;
    while( tc-- ){
        int n, e;
        cin >> n >> e;

        vector<int> a(n);
        for( auto &i : a ){
            cin >> i;
            if( i == 1 ){
                i = 0;
                continue;
            }
            if( pr[i] )
                i = 1;
            else
                i = -1;
        }

        vector<vector<ll>> dp(n,vector<ll>(2,0));
        ll ans = 0;
        for(int i=0; i<n; i++){
            if( a[i] == 0 ){
                if( i >= e ) dp[i][0] += dp[i-e][0];
                if( i >= e ) dp[i][1] += dp[i-e][1];
                dp[i][0] ++;
                ans += dp[i][1];
            }
            if( a[i] == 1 ){
                if( i >= e ) dp[i][1] += dp[i-e][0];
                ans += dp[i][1];
                dp[i][1] ++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}