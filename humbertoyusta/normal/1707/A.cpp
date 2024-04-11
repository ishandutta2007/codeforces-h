#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 100010;
const int mod = 1000000007;
const ll INF = 1ll * mod * mod;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (auto &i : a)
            cin >> i;

        vector<int> ans(n);
        int x = 0;

        for (int i=n-1; i>=0; i--)
        {
            if (a[i] <= x)
            {
                ans[i] = 1;
            }
            else
            {
                if (x + 1 <= q)
                {
                    x ++;
                    ans[i] = 1;
                }
                else
                {
                    ans[i] = 0;
                }
            }
        }

        for (int i=0; i<n; i++)
            cout << ans[i];
        cout << '\n';
    }

    return 0;
}